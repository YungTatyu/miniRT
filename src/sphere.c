
#include "miniRT.h"
#include "parse.h"
#include "vector3d.h"
#include <math.h>
#include <mlx.h>

#define DIFFUSE_REFLECTION 0.69f /* 拡散反射係数 */
#define AMBIENT_LIGHT_REFLECTION 0.01f /* 環境光反射係数 */
#define SPECULAR_REFLECTION 0.3f /* 鏡面反射係数 */
#define COLOR 255.0f /* colorの範囲 */

static float	_calc_t(float a, float b, float c)
{
	const float	t1 = -b + sqrtf(powf(b, 2.0f) - (4.0f * a * c)) / (2.0f * a);
	const float	t2 = -b - sqrtf(powf(b, 2.0f) - (4.0f * a * c)) / (2.0f * a);

	if (t1 > 0.0f && t2 > 0.0f)
		return (fminf(t1, t2));
	else
		return (fmaxf(t1, t2));
}

/**
 * @brief 球体とレイの交差判定をおこなう
 *
 * 解の公式に代入する
 *
 * @param ray
 * @param camera_pos
 * @param obj_pos
 * @param radius
 * @return float t レイのベクトル方程式：𝐩⃗ =𝐬⃗ +𝑡𝐝⃗
 */
float	hit_sphere(t_vector3d ray, t_vector3d camera_pos,
						t_vector3d obj_pos, float radius)
{
	const float	a = vector3d_mag_sq(ray);
	const float	b = 2.0f * vector3d_dot(vector3d_sub(camera_pos, obj_pos), ray);
	const float	c = vector3d_mag_sq(
			vector3d_sub(camera_pos, obj_pos)) - powf(radius, 2.0f);
	const float	d = powf(b, 2.0f) - (4.0f * a * c);

	if (d == 0.0f)
		return (-(b) / 2.0f * a);
	return (_calc_t(a, b, c));
}

/**
 * @brief 入射ベクトルと法線ベクトルの内積を返す
 *
 * intersection_pos:rayとオブジェクトの交点位置
 * incidence_vec:入射ベクトル
 * normal:法線ベクトル
 * dot:内積
 * 内積の値は[0,1]の範囲に制限する
 *
 * @param data
 * @param ray
 * @param t
 * @return float
 */
static float	_get_incidence_dot(t_global_data *data, t_vector3d ray, const float t)
{
	const t_vector3d	intersection_pos = vector3d_add(
			data->camera->coordinate, vector3d_fmulv(t, ray));
	const t_vector3d	incidence_vec = vector3d_sub(
			data->light->coordinate, intersection_pos);
	const t_vector3d	normal = vector3d_sub(
			intersection_pos, data->camera->coordinate);
	float				dot;

	dot = vector3d_dot(normal, incidence_vec);
	if (dot > 1.0f)
		dot = 1.0f;
	else if (dot < 0.0f)
		dot = 0.0f;
	return (dot);
}


/**
 * @brief 直接光の拡散反射光の放射輝度𝑅𝑑の内積を計算する
 *
 * @param ray
 * @param incidence_vec 入射ベクトル
 * @param normal 法線ベクトル
 * @return float
 */
static float	_calc_ligth_specular_reflection_radiance_dot(t_vector3d ray, t_vector3d incidence_vec, t_vector3d normal)
{
	const t_vector3d	regular_reflection = vector3d_sub(
			vector3d_fmulv(2.0f * vector3d_dot(normal, incidence_vec),
				normal),
			incidence_vec);
	const t_vector3d	rev_ray = vector3d_normalize(
			vector3d_fmulv(-1.0f, ray));
	float				dot;

	dot = vector3d_dot(rev_ray, regular_reflection);
	if (dot > 1.0f)
		dot = 1.0f;
	else if (dot < 0.0f)
		dot = 0.0f;
	return (dot);
}

/**
 * @brief 直接光の拡散反射光の放射輝度𝑅𝑑を計算する
 *
 * intersection_pos:交点位置
 * incidence_vec:入射ベクトル
 * normal:法線ベクトル
 * _dot:内積
 *
 * @param data
 * @param ray
 * @param dot
 * @param t
 * @return float
 */
static float	_get_ligth_specular_reflection_radiance(
			t_global_data *data, t_vector3d ray, const float dot, const float t)
{
	const t_vector3d	intersection_pos = vector3d_add(
			data->camera->coordinate, vector3d_fmulv(t, ray));
	const t_vector3d	incidence_vec = vector3d_sub(
			data->light->coordinate, intersection_pos);
	const t_vector3d	normal = vector3d_sub(
			intersection_pos, data->camera->coordinate);
	float				_dot;

	if (dot <= 0.0f)
		return (0.0f);
	_dot = _calc_ligth_specular_reflection_radiance_dot(
			ray, incidence_vec, normal);
	return (SPECULAR_REFLECTION * data->light->ratio * _dot);
}


/**
 * @brief 反射光の放射輝度𝑅𝑟を計算する
 *
 * ambient_light_radiance:環境光の反射光の放射輝度
 * light_diffuse_radiance:直接光の拡散反射光の放射輝度
 * ligth_specular_reflection_radiance:直接光の鏡面反射光の放射輝度
 *
 * @param data
 * @param ray
 * @param t
 * @return float
 */
static	float	_calc_shade(t_global_data *data, t_vector3d ray, const float t)
{
	const float	ambient_light_radiance = AMBIENT_LIGHT_REFLECTION
		* data->ambient_light->ratio;
	const float	light_diffuse_radiance
		= DIFFUSE_REFLECTION * data->light->ratio
		* _get_incidence_dot(data, ray, t);
	const float	ligth_specular_reflection_radiance
		= _get_ligth_specular_reflection_radiance(data, ray,
			_get_incidence_dot(data, ray, t), t);
	float		sum_radiance;

	sum_radiance = ambient_light_radiance
		+ light_diffuse_radiance + ligth_specular_reflection_radiance;
	if (sum_radiance > 1.0f)
		sum_radiance = 1.0f;
	else if (sum_radiance < 0.0f)
		sum_radiance = 0.0f;
	return (sum_radiance);
}

void	render_sphere_loop(t_global_data *data, t_sphere *sphere)
{
	int			y;
	int			x;
	t_vector3d	coordinate;
	t_vector3d	camera_ray;
	float	t;
	float	radiance;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate(x, y);
			camera_ray = vector3d_sub(coordinate, data->camera->coordinate);
			t = hit_sphere(camera_ray, data->camera->coordinate, sphere->coordinate, sphere->radius);
			if (t >= 0.0f)
			{
				radiance = _calc_shade(data, camera_ray, t);
				printf("%f\n", radiance);
				// my_mlx_pixel_put(data, x, y, create_rgb(sphere->red, sphere->green, sphere->blue));
				// my_mlx_pixel_put(data, x, y, create_rgb(sphere->red * radiance, sphere->green * radiance, sphere->blue * radiance));
				my_mlx_pixel_put(data, x, y, create_rgb(radiance, radiance, radiance));
			}
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
