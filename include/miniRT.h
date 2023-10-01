/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:23 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 17:03:12 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "objs.h"

typedef struct s_ambient_lightning
{
	int		red;
	int		green;
	int		blue;
	float	ratio;
}t_ambient_lightning;

typedef struct s_camera
{
	float	x;
	float	y;
	float	z;
	float	x_axis;
	float	y_axis;
	float	z_axis;
	int		fov;
}t_camera;

typedef struct s_light
{
	float	x;
	float	y;
	float	z;
	float	ratio;
	int		red;
	int		green;
	int		blue;
}t_light;

typedef struct s_sphere
{
	float	x;
	float	y;
	float	z;
	float	diameter;
	float	radius;
	int		red;
	int		green;
	int		blue;
}t_sphere;

typedef struct s_plane
{
	float	x;
	float	y;
	float	z;
	float	x_axis;
	float	y_axis;
	float	z_axis;
	int		red;
	int		green;
	int		blue;
}t_plane;

typedef struct s_cylinder
{
	float	x;
	float	y;
	float	z;
	float	x_axis;
	float	y_axis;
	float	z_axis;
	int		red;
	int		green;
	int		blue;
	float	diameter;
	float	radius;
	float	height;
}t_cylinder;

typedef struct s_global_data
{
	void				*mlx;
	void				*mlx_win;
	int					height;
	int					width;
	t_ambient_lightning	*ambient_light;
	t_camera			*camera;
	t_light				*light;
	t_objs				*objs_list;
}t_global_data;

#endif
