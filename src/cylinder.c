/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:15:30 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/10 16:00:46 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

bool			check_cylinder_cross(float dot, float height, float t);
t_cylinder_ray	get_cylinder_ray(t_vector3d start_pos, t_cylinder *cylinder,
					t_t_data t, t_vector3d camera_ray);
t_fcolor	get_radiance(t_global_data *data, t_objs *node,
				t_vector3d ray, const float t);

float	hit_cylinder(t_vector3d ray, t_vector3d start_pos,
			t_cylinder *cylinder)
{
	t_t_data	t;
	t_cylinder_ray	ray_cylinder;

	t.a = vector3d_mag_sq(vector3d_cross(ray, cylinder->direction));
	if (t.a == 0.0f)
		return (-1.0f);
	t.b = 2.0f * (vector3d_dot(vector3d_cross(ray, cylinder->direction),
				vector3d_cross(vector3d_sub(start_pos, cylinder->coordinate),
					cylinder->direction)));
	t.c = vector3d_mag_sq(vector3d_cross(
				vector3d_sub(start_pos, cylinder->coordinate),
				cylinder->direction)) - powf(cylinder->radius, 2.0f);
	t.d = powf(t.b, 2.0f) - (4.0f * t.a * t.c);
	if (t.d == 0)
		t.t = (-(t.b) / (2.0f * t.a));
	t.t1 = (-t.b + sqrtf(powf(t.b, 2.0f) - (4.0f * t.a * t.c))) / (2.0f * t.a);
	t.t2 = (-t.b - sqrtf(powf(t.b, 2.0f) - (4.0f * t.a * t.c))) / (2.0f * t.a);
	ray_cylinder = get_cylinder_ray(start_pos, cylinder, t, ray);
	if (check_cylinder_cross(vector3d_dot(ray_cylinder.ray_t1, cylinder->direction), cylinder->height, t.t1))
		t.t = t.t1;
	else if (check_cylinder_cross(vector3d_dot(ray_cylinder.ray_t2, cylinder->direction), cylinder->height, t.t2))
		t.t = t.t2;
	else
		t.t = -1.0f;
	return (t.t);
}

void	render_cylinder_loop(t_global_data *data, t_objs *node)
{
	int				y;
	int				x;
	t_vector3d		camera_ray;
	t_cylinder		*cylinder;
	t_fcolor		radiance;
	float			t;

	cylinder = (t_cylinder *)node->obj;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			camera_ray = get_camera_ray_dynamic(x, y, data);
			t = hit_cylinder(camera_ray, data->camera->coordinate, cylinder);
			if (t < 0.0f)
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			else
			{
				radiance = get_radiance(data, node, camera_ray, t);
				my_mlx_pixel_put(data, x, y, create_rgb(radiance.red, radiance.green, radiance.blue));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
