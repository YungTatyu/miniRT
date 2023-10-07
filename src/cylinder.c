#include "miniRT.h"
#include "parse.h"
#include <mlx.h>
#include <math.h>

static float	_calc_t(float a, float b, float c)
{
	const float	t1 = (-b + sqrtf(powf(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);
	const float	t2 = (-b - sqrtf(powf(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);


	if (t1 > 0.0f && t2 > 0.0f)
		return (fminf(t1, t2));
	else
		return (fmaxf(t1, t2));
}

t_vector3d vector3d_cross(t_vector3d v1, t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

bool	hit_cylinder(t_vector3d ray, t_vector3d camera_pos,
						t_vector3d obj_pos, float radius, t_cylinder *cylinder)
{
	t_vector3d	cylinder_bottom;

	cylinder_bottom.x = obj_pos.x;
	cylinder_bottom.y = obj_pos.y - (cylinder->height / 2.0f);
	cylinder_bottom.z = obj_pos.z;
	const float	a = vector3d_mag_sq(vector3d_cross(ray, cylinder->direction));
	if (a == 0.0f)
		return (false);
	const float b = 2.0f * (vector3d_dot(vector3d_cross(ray, cylinder->direction),
					vector3d_cross(vector3d_sub(camera_pos, cylinder_bottom), cylinder->direction)));
	const float	c = vector3d_mag_sq(vector3d_cross(
			vector3d_sub(camera_pos,cylinder_bottom), cylinder->direction)) - powf(radius, 2.0f);
	const float	d = powf(b, 2.0f) - (4.0f * a * c);
	if (d < 0)
		return (false);
	return (true);
}

void	render_cylinder_loop(t_global_data *data, t_cylinder *cylinder)
{
	int			y;
	int			x;
	t_vector3d	coordinate;
	t_vector3d	camera_ray;
	t_vector3d	ray1;
	t_vector3d	ray2;
	t_vector3d	y_axis;
	float	t;
	float	radiance;
	t_vector3d	cylinder_bottom;

	cylinder_bottom.x = cylinder->coordinate.x;
	cylinder_bottom.y = cylinder->coordinate.y - (cylinder->height / 2.0f);
	cylinder_bottom.z = cylinder->coordinate.z;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate(x, y);
			camera_ray = vector3d_sub(coordinate, data->camera->coordinate);
			if (hit_cylinder(camera_ray, data->camera->coordinate, cylinder->coordinate, cylinder->radius, cylinder))
			{
				// const float	a = vector3d_mag_sq(vector3d_cross(camera_ray, cylinder->direction));
				// const float b = 2.0f * (vector3d_dot(vector3d_cross(camera_ray, cylinder->direction),
				// 				vector3d_cross(vector3d_sub(data->camera->coordinate, cylinder_bottom), cylinder->direction)));
				// const float	c = vector3d_mag_sq(vector3d_cross(
				// 		vector3d_sub(data->camera->coordinate,cylinder_bottom), cylinder->direction)) - powf(cylinder->radius, 2.0f);
				// const float	t1 = -b + sqrtf(powf(b, 2.0f) - (4.0f * a * c)) / (2.0f * a);
				// const float	t2 = -b - sqrtf(powf(b, 2.0f) - (4.0f * a * c)) / (2.0f * a);
				// t = fminf(t1, t2);
				// ray1 = vector3d_add(data->camera->coordinate, vector3d_fmulv(t, camera_ray));
				my_mlx_pixel_put(data, x, y, create_rgb(cylinder->color.red, cylinder->color.green, cylinder->color.blue));
				// if (fabsf(ray1.y - cylinder->coordinate.y) <= cylinder->height / 2.0f)
				// 	my_mlx_pixel_put(data, x, y, create_rgb(cylinder->color.red, cylinder->color.green, cylinder->color.blue));
				// else
				// 	my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
				// ray2 = vector3d_add(data->camera->coordinate, vector3d_fmulv(t2, camera_ray));
			}
			// if (t >= 0.0f)
			// {
			// 	// radiance = _calc_shade(data, cylinder, camera_ray, t);
			// 	// printf("radiance=%f\n", radiance);
			// 	my_mlx_pixel_put(data, x, y, create_rgb(cylinder->color.red, cylinder->color.green, cylinder->color.blue));
			// 	// my_mlx_pixel_put(data, x, y, create_rgb(cylinder->color.red * radiance, cylinder->color.green * radiance, cylinder->color.blue * radiance));
			// 	// my_mlx_pixel_put(data, x, y, create_rgb(radiance, radiance, radiance));
			// }
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
