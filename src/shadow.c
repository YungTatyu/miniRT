/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:07:26 by tterao            #+#    #+#             */
/*   Updated: 2023/10/11 16:22:19 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#define C_EPSILON 512.0

/**
 * @brief shadowの計算をする
 *
 * @param data
 * @param shadow_ray
 * @param intersection_pos
 * @return double
 */
double	shadow_res(t_global_data *data, t_vector3d shadow_ray,
					t_vector3d intersection_pos)
{
	t_objs				*obj;
	const t_vector3d	shadow_ray_start = vector3d_add(intersection_pos,
			vector3d_fmulv((1.0 / C_EPSILON), shadow_ray));
	const double		t = hit_object(shadow_ray_start, data->objs_list,
			shadow_ray, &obj) + (1.0 / C_EPSILON);
	const double		distance_to_light = vector3d_mag(vector3d_sub(
				data->light->coordinate, intersection_pos))
		- (1.0 / C_EPSILON);

	if (t < distance_to_light)
		return (t);
	return (-1.0);
}
