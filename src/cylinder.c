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
							vector3d_cross(vector3d_sub(camera_pos, cylinder->coordinate), cylinder->direction)));
	const float	c = vector3d_mag_sq(vector3d_cross(
						vector3d_sub(camera_pos, cylinder->coordinate), cylinder->direction)) - powf(cylinder->radius, 2.0f);
	const float	d = powf(b, 2.0f) - (4.0f * a * c);
	if (d < 0)
		return (false);
	return (true);
}


t_vector3d	get_3d_coordinate_new(int x, int y , t_global_data *data);

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


	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate_new(x, y, data);
			camera_ray = vector3d_sub(coordinate, data->camera->coordinate);
			if (hit_cylinder(camera_ray, data->camera->coordinate, cylinder->coordinate, cylinder->radius, cylinder))
			{
				float	a = vector3d_mag_sq(vector3d_cross(camera_ray, cylinder->direction));
				float b = 2.0f * (vector3d_dot(vector3d_cross(camera_ray, cylinder->direction),
								vector3d_cross(vector3d_sub(data->camera->coordinate, cylinder->coordinate), cylinder->direction)));
				float	c = vector3d_mag_sq(vector3d_cross(
						vector3d_sub(data->camera->coordinate, cylinder->coordinate), cylinder->direction)) - powf(cylinder->radius, 2.0f);
				float	t1 = (-b + sqrtf(powf(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);
				float	t2 = (-b - sqrtf(powf(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);
				float	d = powf(b, 2.0f) - (4.0f * a * c);
				if (d == 0)
					t = (-(b) / (2.0f * a));
				else
				{
					ray1 = vector3d_sub(vector3d_add(data->camera->coordinate, vector3d_fmulv(t1, camera_ray)), cylinder->coordinate);
					ray2 = vector3d_sub(vector3d_add(data->camera->coordinate, vector3d_fmulv(t2, camera_ray)), cylinder->coordinate);
					// printf("ray1 vector3d_dot:%f\n", vector3d_dot(ray1, cylinder->direction));
					// printf("ray2 vector3d_dot:%f\n", vector3d_dot(ray2, cylinder->direction));
					if (0 <= vector3d_dot(ray1, cylinder->direction) && vector3d_dot(ray1, cylinder->direction) < cylinder->height && t1 > 0.0f)
					{
						printf("T1\n");
						t = t1;
					}
					else if (0 <= vector3d_dot(ray2, cylinder->direction) && vector3d_dot(ray2, cylinder->direction) < cylinder->height && t2 > 0.0f)
					{
						printf("T2\n");
						t = t2;
					}
					else
						t = -1.0f;
				}
				// printf("t:%f t1:%f t2:%f\n", t, t1, t2);
				if (t < 0.0f)
					my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
				else
				{
					my_mlx_pixel_put(data, x, y, create_rgb(cylinder->color.red, cylinder->color.green, cylinder->color.blue));
				}
			}
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
