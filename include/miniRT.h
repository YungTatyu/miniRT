/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:23 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 14:20:38 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


typedef struct s_ambient_lightning
{
	int		red;
	int		green;
	int		blue;
	float	ratio;
}t_s_ambient_lightning;

typedef struct s_camera
{
	int		x;
	int		y;
	int		z;
	float	x_axis;
	float	y_axis;
	float	z_axis;
	int		fov;
}t_camera;

typedef struct s_light
{
	int		x;
	int		y;
	int		z;
	float	ratio;
	int		red;
	int		green;
	int		blue;
}t_light;

typedef struct s_sphere
{
	int		x;
	int		y;
	int		z;
	float	diameter;
	float	radius;
	int		red;
	int		green;
	int		blue;
}t_sphere;

typedef struct s_plane
{
	int		x;
	int		y;
	int		z;
	float	x_axis;
	float	y_axis;
	float	z_axis;
	int		red;
	int		green;
	int		blue;
}t_plane;

typedef struct s_cylinder
{
	int		x;
	int		y;
	int		z;
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

enum e_obj_type
{
	HEAD,
	PALNE,
	SPHERE,
	CYLINDER,
};

typedef struct s_objs
{
	e_obj_type		type;
	void			*obj;
	struct s_objs	*next;
}t_objs;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
}t_window;

#endif
