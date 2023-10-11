/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:17:30 by tterao            #+#    #+#             */
/*   Updated: 2023/10/11 16:17:41 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief 平面とレイの交差判定をおこなう
 *
 * @param ray
 * @param camera_pos
 * @param obj_pos
 * @param obj_dir
 * @return double t cameraからobjectまでの距離のベクトルの大きさを示すtが返す
 */
double	hit_plane(t_vector3d ray, t_vector3d camera_pos,
						t_vector3d obj_pos, t_vector3d obj_dir)
{
	double	t;

	t = -1.0 * (vector3d_dot(
				vector3d_sub(camera_pos, obj_pos),
				obj_dir))
		/ vector3d_dot(ray, obj_dir);
	if (isnan(t))
		t = -1.0;
	return (t);
}
