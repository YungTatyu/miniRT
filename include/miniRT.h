/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:23 by tterao            #+#    #+#             */
/*   Updated: 2023/10/11 16:10:47 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "objs.h"
# include "vector3d.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define ESC_KEY 53

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}t_color;

typedef struct s_vector2d
{
	int	x;
	int	y;
}t_vector2d;

typedef struct s_fcolor
{
	double	red;
	double	green;
	double	blue;
}t_fcolor;

typedef struct s_ambient_lightning
{
	t_color	color;
	double	ratio;
}t_ambient_lightning;

typedef struct s_camera
{
	t_vector3d	coordinate;
	t_vector3d	direction;
	int			fov;
}t_camera;

typedef struct s_light
{
	t_vector3d	coordinate;
	t_vector3d	direction;
	double		ratio;
	t_color		color;
}t_light;

typedef struct s_sphere
{
	t_vector3d	coordinate;
	double		diameter;
	double		radius;
	t_color		color;
}t_sphere;

typedef struct s_plane
{
	t_vector3d	coordinate;
	t_vector3d	direction;
	t_color		color;
}t_plane;

typedef struct s_cylinder
{
	t_vector3d	coordinate;
	t_vector3d	direction;
	t_color		color;
	double		diameter;
	double		radius;
	double		height;
}t_cylinder;

typedef struct s_global_data
{
	void				*mlx;
	void				*mlx_win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					height;
	int					width;
	t_color				background;
	t_ambient_lightning	*ambient_light;
	t_camera			*camera;
	t_light				*light;
	t_objs				*objs_list;
}t_global_data;

typedef struct s_t_data
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;
	double	t1;
	double	t2;
}t_t_data;

typedef struct s_cylinder_ray
{
	t_vector3d	ray_t1;
	t_vector3d	ray_t2;
}t_cylinder_ray;

typedef struct s_screen_data
{
	t_vector3d	up;
	t_vector3d	screen_unit_x;
	t_vector3d	screen_unit_y;
	double		camera_to_screen;
	double		f_x;
	double		f_y;
	double		w_s;
	double		h_s;
}t_screen_data;

void		*try_calloc(size_t count, size_t size);
void		*try_malloc(size_t size);
void		render(t_global_data *data);
t_vector3d	get_camera_ray(int x, int y, t_global_data *data);
t_vector3d	get_camera_ray_dynamic(int x, int y, t_global_data *data);;
void		my_mlx_pixel_put(t_global_data *data, int x, int y, int color);
int			create_rgb(int r, int g, int b);
void		color_add(t_color color, double adding_num);
double		color_to_fcolor(double color);
double		color_to_color(double fcolor);
double		constrain(double n, double min, double max);
t_fcolor	get_radiance(t_global_data *data, t_objs *node,
				t_vector3d ray, const double t);
double		hit_sphere(t_vector3d ray, t_vector3d camera_pos,
				t_vector3d obj_pos, double radius);
double		hit_plane(t_vector3d ray, t_vector3d camera_pos,
				t_vector3d obj_pos, t_vector3d obj_dir);
double		hit_cylinder(t_vector3d ray, t_vector3d start_pos,
				t_cylinder *cylinder);
double		hit_object(t_vector3d start_pos, t_objs *head,
				t_vector3d ray, t_objs **obj);
void		render_loop(t_global_data *data);

#endif
