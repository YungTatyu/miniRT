/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:25:14 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/11 16:10:47 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}t_vector3d;

t_vector3d	vector3d_add(const t_vector3d v1, const t_vector3d v2);
t_vector3d	vector3d_sub(const t_vector3d v1, const t_vector3d v2);
t_vector3d	vector3d_mul(const t_vector3d v1, const t_vector3d v2);
t_vector3d	vector3d_div(const t_vector3d v1, const t_vector3d v2);
double		vector3d_dot(const t_vector3d v1, const t_vector3d v2);
double		vector3d_mag_sq(const t_vector3d v);
double		vector3d_mag(const t_vector3d v);
void		vector3d_print(const t_vector3d v);
t_vector3d	vector3d_fmulv(double f, const t_vector3d v);
t_vector3d	vector3d_normalize(const t_vector3d v);
t_vector3d	vector3d_cross(const t_vector3d v1, const t_vector3d v2);
t_vector3d	vector3d_create(double x, double y, double z);

#endif
