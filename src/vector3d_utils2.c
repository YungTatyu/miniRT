/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:48:29 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/11 16:10:47 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

/**
 * @brief 外積を計算する
 *
 * @param v1
 * @param v2
 * @return t_vector3d
 */
t_vector3d	vector3d_cross(const t_vector3d v1, const t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_vector3d	vector3d_create(double x, double y, double z)
{
	t_vector3d	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
