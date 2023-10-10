/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_incidence_dot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:54:43 by tterao            #+#    #+#             */
/*   Updated: 2023/10/10 15:34:59 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief rayとオブジェクトの交点位置を取得
 *
 * @param camera_pos
 * @param t
 * @param ray
 * @return t_vector3d
 */
t_vector3d	get_intersection_pos(
		const t_vector3d camera_pos, const float t, const t_vector3d ray)
{
	return (vector3d_add(camera_pos, vector3d_fmulv(t, ray)));
}

/**
 * @brief 入射ベクトルを取得
 *
 * @param light_pos
 * @param intersection_pos
 * @return t_vector3d
 */
t_vector3d	get_incidence_vector(
		const t_vector3d light_pos, const t_vector3d intersection_pos)
{
	return (vector3d_normalize(vector3d_sub(light_pos, intersection_pos)));
}

/**
 * @brief 法線ベクトルを取得
 *
 * 平面の場合、平面の向きが法線ベクトルになる
 * 球体の場合、法線ベクトルを計算する
 *
 * @param intersection_pos
 * @param node
 * @return t_vector3d
 */
t_vector3d	get_normal_vector(
		const t_vector3d intersection_pos, const t_objs *node)
{
	if (node->type == PLANE)
		return (((t_plane *)node->obj)->direction);
	// else if (node->type == SPHERE)
	return (vector3d_normalize(vector3d_sub(intersection_pos, objs_get_coordinate(node))));
}

/**
 * @brief 入射ベクトルと法線ベクトルの内積を返す
 *
 * intersection_pos:rayとオブジェクトの交点位置
 * incidence_vec:入射ベクトル
 * normal:法線ベクトル
 * dot:内積
 * 内積の値は[0,1]の範囲に制限する
 *
 * @param data
 * @param ray
 * @param t
 * @return float
 */
float	get_incidence_dot(t_global_data *data, const t_objs *node,
						const t_vector3d ray, const float t)
{
	const t_vector3d	intersection_pos = get_intersection_pos(
			data->camera->coordinate, t, ray);
	const t_vector3d	incidence_vec = get_incidence_vector(
			data->light->coordinate, intersection_pos);
	const t_vector3d	normal = get_normal_vector(
			intersection_pos, node);
	float				dot;

	dot = vector3d_dot(normal, incidence_vec);
	return (constrain(dot, 0.0f, 1.0f));
}
