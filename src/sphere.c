
#include "miniRT.h"
#include "parse.h"
#include "vector3d.h"
#include <math.h>
#include <mlx.h>

t_fcolor	get_radiance(t_global_data *data, t_sphere *sphere,
				t_vector3d ray, const float t);

/**
 * @brief 解の公式のtを求める、二つのtのうち，値が正でかつ小さい方を𝑡とする
 *
 * @param a
 * @param b
 * @param c
 * @return float
 */
static float	_calc_t(float a, float b, float c)
{
	const float	t1 = (-b + sqrtf(powf(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);
	const float	t2 = (-b - sqrtf(powf(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);

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
		return (-(b) / (2.0f * a));
	else if (d < 0)
		return (-1.0f);
	return (_calc_t(a, b, c));
}

/**
 * @brief 値nをmin~maxまでの範囲に制限する
 *
 * @param n
 * @param min
 * @param max
 * @return float
 */
float	constrain(float n, float min, float max)
{
	if (n > max)
		n = max;
	else if (n < min)
		n = min;
	return (n);
}

void	render_sphere_loop(t_global_data *data, t_sphere *sphere)
{
	int			y;
	int			x;
	t_vector3d	camera_ray;
	float	t;
	t_fcolor	radiance;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			camera_ray = get_camera_ray(x, y, data);
			t = hit_sphere(camera_ray, data->camera->coordinate, sphere->coordinate, sphere->radius);
			// printf("t=%f\n", t);
			if (t >= 0.0f)
			{
				radiance = get_radiance(data, sphere, camera_ray, t);
				my_mlx_pixel_put(data, x, y, create_rgb(radiance.red, radiance.green, radiance.blue));
			}
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
