/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:32 by tterao            #+#    #+#             */
/*   Updated: 2023/10/09 17:15:58 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

/**
 * @brief ベクトルの内積を返す
 *
 * @param v1
 * @param v2
 * @return float
 */
float	vector3d_dot(const t_vector3d v1, const t_vector3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/**
 * @brief ベクトルの大きさの二乗を返す
 *
 * @param v
 * @return float
 */
float	vector3d_mag_sq(const t_vector3d v)
{
	return (powf(v.x, 2.0f) + powf(v.y, 2.0f) + powf(v.z, 2.0f));
}

/**
 * @brief ベクトルの大きさを返す
 *
 * @param v
 * @return float
 */
float	vector3d_mag(const t_vector3d v)
{
	return (sqrtf(vector3d_mag_sq(v)));
}

/**
 * @brief f × vを返す
 *
 * @param f
 * @param v
 * @return t_vector3d
 */
t_vector3d	vector3d_fmulv(float f, const t_vector3d v)
{
	t_vector3d	result;

	result.x = f * v.x;
	result.y = f * v.y;
	result.z = f * v.z;
	return (result);
}

/**
 * @brief ベクトルvを正規化する
 *
 * @param v
 * @return t_vector3d
 */
t_vector3d	vector3d_normalize(const t_vector3d v)
{
	const float	magnitude = vector3d_mag(v);
	t_vector3d	result;

	result.x = v.x / magnitude;
	result.y = v.y / magnitude;
	result.z = v.z / magnitude;
	return (result);
}
