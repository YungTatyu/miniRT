/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:33:01 by tterao            #+#    #+#             */
/*   Updated: 2023/10/14 14:34:31 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include <mlx.h>
#include <math.h>

void		render_cylinder_loop(t_global_data *data, t_objs *node);
void		render_sphere_loop(t_global_data *data, t_objs *node);
t_fcolor	get_radiance(t_global_data *data, t_objs *node,
				t_vector3d ray, const double t);
int			close_esc(int keycode, t_global_data *data);
int			close_x(t_global_data *data);

void	_mlx_init(t_global_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->width,
			data->height, "miniRT");
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_global_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	render(t_global_data *data)
{
	t_objs	*node;

	_mlx_init(data);
	node = data->objs_list->next;
	render_loop(data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 0, close_esc, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0, close_x, data);
	mlx_loop(data->mlx);
}
