/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:31:22 by tterao            #+#    #+#             */
/*   Updated: 2023/10/14 14:31:24 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

t_vector3d	vector3d_add(const t_vector3d v1, const t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector3d	vector3d_sub(const t_vector3d v1, const t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector3d	vector3d_mul(const t_vector3d v1, const t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

t_vector3d	vector3d_div(const t_vector3d v1, const t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	return (result);
}

void	vector3d_print(const t_vector3d v)
{
	printf("x=%f, y=%f, z=%f\n", v.x, v.y, v.z);
}
