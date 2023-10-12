/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:22:01 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/11 16:10:47 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_cylinder_cross(double dot, double height, double t)
{
	if (0 <= dot && dot <= height && t > 0)
		return (true);
	else
		return (false);
}

t_cylinder_ray	get_cylinder_ray(t_vector3d start_pos, t_cylinder *cylinder,
						t_t_data t, t_vector3d camera_ray)
{
	t_cylinder_ray	ray;

	ray.ray_t1 = vector3d_sub(vector3d_add(start_pos,
				vector3d_fmulv(t.t1, camera_ray)), cylinder->coordinate);
	ray.ray_t2 = vector3d_sub(vector3d_add(start_pos,
				vector3d_fmulv(t.t2, camera_ray)), cylinder->coordinate);
	return (ray);
}
