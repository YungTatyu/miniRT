/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:15:30 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/14 14:32:00 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

bool			check_cylinder_cross(double dot, double height, double t);
t_cylinder_ray	get_cylinder_ray(t_vector3d start_pos, t_cylinder *cylinder,
					t_t_data t, t_vector3d camera_ray);
t_fcolor		get_radiance(t_global_data *data, t_objs *node,
					t_vector3d ray, const double t);

static double	_calc_t(t_cylinder *cylinder,
					t_cylinder_ray ray_cylinder, t_t_data t)
{
	if (check_cylinder_cross(vector3d_dot(
				ray_cylinder.ray_t1, cylinder->direction),
			cylinder->height, t.t1))
		t.t = t.t1;
	else if (check_cylinder_cross(vector3d_dot(
				ray_cylinder.ray_t2, cylinder->direction),
			cylinder->height, t.t2))
		t.t = t.t2;
	else
		t.t = -1.0;
	cylinder->t = t;
	return (t.t);
}

double	hit_cylinder(t_vector3d ray, t_vector3d start_pos,
						t_cylinder *cylinder)
{
	t_t_data		t;
	t_cylinder_ray	ray_cylinder;

	t.a = vector3d_mag_sq(vector3d_cross(ray, cylinder->direction));
	if (t.a == 0.0)
		return (-1.0);
	t.b = 2.0 * (vector3d_dot(vector3d_cross(ray, cylinder->direction),
				vector3d_cross(vector3d_sub(start_pos, cylinder->coordinate),
					cylinder->direction)));
	t.c = vector3d_mag_sq(vector3d_cross(
				vector3d_sub(start_pos, cylinder->coordinate),
				cylinder->direction)) - pow(cylinder->radius, 2.0);
	t.d = pow(t.b, 2.0) - (4.0 * t.a * t.c);
	if (t.d == 0)
		t.t = (-(t.b) / (2.0 * t.a));
	t.t1 = (-t.b - sqrt(pow(t.b, 2.0) - (4.0 * t.a * t.c))) / (2.0 * t.a);
	t.t2 = (-t.b + sqrt(pow(t.b, 2.0) - (4.0 * t.a * t.c))) / (2.0 * t.a);
	ray_cylinder = get_cylinder_ray(start_pos, cylinder, t, ray);
	return (_calc_t(cylinder, ray_cylinder, t));
}
