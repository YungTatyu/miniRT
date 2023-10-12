
#include "miniRT.h"
#include "parse.h"
#include "vector3d.h"
#include <math.h>
#include <mlx.h>

/**
 * @brief 解の公式のtを求める、二つのtのうち，値が正でかつ小さい方を𝑡とする
 *
 * @param a
 * @param b
 * @param c
 * @return double
 */
static double	_calc_t(double a, double b, double c)
{
	const double	t1 = (-b + sqrt(pow(b, 2.0) - (4.0 * a * c))) / (2.0 * a);
	const double	t2 = (-b - sqrt(pow(b, 2.0) - (4.0 * a * c))) / (2.0 * a);

	if (t1 > 0.0 && t2 > 0.0)
		return (fmin(t1, t2));
	else
		return (fmax(t1, t2));
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
 * @return double t レイのベクトル方程式：𝐩⃗ =𝐬⃗ +𝑡𝐝⃗
 */
double	hit_sphere(t_vector3d ray, t_vector3d camera_pos,
						t_vector3d obj_pos, double radius)
{
	const double	a = vector3d_mag_sq(ray);
	const double	b = 2.0 * vector3d_dot(
			vector3d_sub(camera_pos, obj_pos), ray);
	const double	c = vector3d_mag_sq(
			vector3d_sub(camera_pos, obj_pos)) - pow(radius, 2.0);
	const double	d = pow(b, 2.0) - (4.0 * a * c);

	if (d == 0.0)
		return (-(b) / (2.0 * a));
	else if (d < 0)
		return (-1.0);
	return (_calc_t(a, b, c));
}

/**
 * @brief 値nをmin~maxまでの範囲に制限する
 *
 * @param n
 * @param min
 * @param max
 * @return double
 */
double	constrain(double n, double min, double max)
{
	if (n > max)
		n = max;
	else if (n < min)
		n = min;
	return (n);
}

void	render_sphere_loop(t_global_data *data, t_objs *node)
{
	int			y;
	int			x;
	t_vector3d	camera_ray;
	double		t;
	t_fcolor	radiance;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			camera_ray = get_camera_ray_dynamic(x, y, data);
			t = hit_sphere(camera_ray, data->camera->coordinate, objs_get_coordinate(node), ((t_sphere *)node->obj)->radius);
			// printf("t=%f\n", t);
			if (t >= 0.0)
			{
				radiance = get_radiance(data, node, camera_ray, t);
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
