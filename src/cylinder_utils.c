/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:22:01 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/08 14:22:47 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_cylinder_cross(float dot, float height, float t)
{
	if (0 <= dot && dot <= height && t > 0)
		return (true);
	else
		return (false);
}

t_cylinder_ray	get_cylinder_ray(t_global_data *data, t_cylinder *cylinder,
						t_t_data t, t_vector3d camera_ray)
{
	t_cylinder_ray	ray;

	ray.ray_t1 = vector3d_sub(vector3d_add(data->camera->coordinate,
				vector3d_fmulv(t.t1, camera_ray)), cylinder->coordinate);
	ray.ray_t2 = vector3d_sub(vector3d_add(data->camera->coordinate,
				vector3d_fmulv(t.t2, camera_ray)), cylinder->coordinate);
	return (ray);
}
