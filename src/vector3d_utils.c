/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:32 by tterao            #+#    #+#             */
/*   Updated: 2023/10/04 16:32:30 by tterao           ###   ########.fr       */
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
float	vector3d_dot(t_vector3d v1, t_vector3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/**
 * @brief ベクトルの大きさを返す
 *
 * @param v
 * @return float
 */
float	vector3d_mag_sq(t_vector3d v)
{
	return (powf(v.x, 2.0f) + powf(v.y, 2.0f) + powf(v.z, 2.0f));
}

/**
 * @brief ベクトルの大きさの二乗を返す
 *
 * @param v
 * @return float
 */
float	vector3d_mag(t_vector3d v)
{
	return (sqrtf(vector3d_mag_sq(v)));
}
