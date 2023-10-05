
#include "miniRT.h"
#include "parse.h"

static float	_calc_t(float a, float b, float c)
{
	const float	t1 = -b + sqrtf(powf(b, 2.0f) - (4 * a * c)) / (2 * a);
	const float	t2 = -b - sqrtf(powf(b, 2.0f) - (4 * a * c)) / (2 * a);

	if (t1 > t2)
		return (t1);
	else
		return (t2);
}

/**
 * @brief 球体とレイの交差判定をおこなう
 *
 * 解の公式に代入する
 *
 * @param ray
 * @param camera_p
 * @param obj_p
 * @param radius
 * @return float t レイのベクトル方程式：𝐩⃗ =𝐬⃗ +𝑡𝐝⃗
 */
float	hit_sphere(t_vector3d ray, t_vector3d camera_p,
						t_vector3d obj_p, float radius)
{
	const float	a = vector3d_mag_sq(ray);
	const float	b = 2.0f * vector3d_dot(vector3d_sub(camera_p, obj_p), ray);
	const float	c = vector3d_mag_sq(
			vector3d_sub(camera_p, obj_p)) - powf(radius, 2.0);
	const float	d = powf(b, 2.0f) - (4 * a * c);

	if (d == 0.0f)
		return (-(b) / 2.0f * a);
	return (powf(b, 2.0f) - (4 * a * c));
}

void	render_sphere_loop(t_global_data *data, t_sphere *sphere)
{
	int			y;
	int			x;
	t_vector3d	coordinate;
	t_vector3d	camera_ray;
	float	t;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate(x, y);
			camera_ray = vector3d_sub(coordinate, data->camera->coordinate);
			// printf("x = %f y = %f z = %f\n", camera_ray.x, camera_ray.y , camera_ray.z);
			t = hit_sphere(camera_ray, data->camera->coordinate, sphere->coordinate, sphere->radius);
			if (t >= 0.0f)
				my_mlx_pixel_put(data, x, y, create_rgb(sphere->red, sphere->green, sphere->blue));
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}