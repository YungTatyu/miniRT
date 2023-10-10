/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:23 by tterao            #+#    #+#             */
/*   Updated: 2023/10/10 15:59:56 by tterao           ###   ########.fr       */
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
	float	red;
	float	green;
	float	blue;
}t_fcolor;

typedef struct s_ambient_lightning
{
	t_color	color;
	float	ratio;
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
	float		ratio;
	t_color		color;
}t_light;

typedef struct s_sphere
{
	t_vector3d	coordinate;
	float		diameter;
	float		radius;
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
	float		diameter;
	float		radius;
	float		height;
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
	float	a;
	float	b;
	float	c;
	float	d;
	float	t;
	float	t1;
	float	t2;
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
	float		camera_to_screen;
	float		f_x;
	float		f_y;
	float		w_s;
	float		h_s;
}t_screen_data;

void		*try_calloc(size_t count, size_t size);
void		*try_malloc(size_t size);
void		render(t_global_data *data);
t_vector3d	get_camera_ray(int x, int y, t_global_data *data);
t_vector3d	get_camera_ray_dynamic(int x, int y, t_global_data *data);;
void		my_mlx_pixel_put(t_global_data *data, int x, int y, int color);
int			create_rgb(int r, int g, int b);
void		color_add(t_color color, float adding_num);
float		color_to_fcolor(float color);
float		color_to_color(float fcolor);
float		constrain(float n, float min, float max);
t_fcolor	get_radiance(t_global_data *data, t_objs *node,
				t_vector3d ray, const float t);
float		hit_sphere(t_vector3d ray, t_vector3d camera_pos,
				t_vector3d obj_pos, float radius);
float		hit_plane(t_vector3d ray, t_vector3d camera_pos,
				t_vector3d obj_pos, t_vector3d obj_dir);
float		hit_cylinder(t_vector3d ray, t_vector3d start_pos,
				t_cylinder *cylinder);
float		hit_object(t_vector3d start_pos, t_objs *head,
				t_vector3d ray, t_objs **obj);
void		render_loop(t_global_data *data);

#endif
