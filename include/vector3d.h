/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:25:14 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/08 14:25:31 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}t_vector3d;

t_vector3d	vector3d_add(t_vector3d v1, t_vector3d v2);
t_vector3d	vector3d_sub(t_vector3d v1, t_vector3d v2);
t_vector3d	vector3d_mul(t_vector3d v1, t_vector3d v2);
t_vector3d	vector3d_div(t_vector3d v1, t_vector3d v2);
float		vector3d_dot(t_vector3d v1, t_vector3d v2);
float		vector3d_mag_sq(t_vector3d v);
float		vector3d_mag(t_vector3d v);
void		vector3d_print(t_vector3d v);
t_vector3d	vector3d_fmulv(float f, t_vector3d v);
t_vector3d	vector3d_normalize(t_vector3d v);
t_vector3d	vector3d_cross(t_vector3d v1, t_vector3d v2);
t_vector3d	vector3d_create(float x, float y, float z);

#endif
