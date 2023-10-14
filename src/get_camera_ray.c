/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:59:02 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/14 10:44:57 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

static bool	_is_direct_y(t_vector3d v)
{
	if (v.x == 0 && (v.y == 1 || v.y == -1) && v.z == 0)
		return (true);
	else
		return (false);
}

void	screen_data_init(int x, int y, t_global_data *data,
				t_screen_data *screen)
{
	if (_is_direct_y(data->camera->direction))
		screen->up = vector3d_create(0.0, 0.0, -1.0);
	else
		screen->up = vector3d_create(0.0, 1.0, 0.0);
	screen->screen_unit_x = vector3d_cross(screen->up, data->camera->direction);
	screen->screen_unit_y = vector3d_cross(data->camera->direction,
			screen->screen_unit_x);
	screen->w_s = 2.0;
	screen->h_s = WINDOW_HEIGHT * screen->w_s / WINDOW_WIDTH;
	screen->camera_to_screen = screen->w_s
		/ (2.0 * (tan((double)(data->camera->fov * M_PI / 180) / 2.0)));
	screen->f_x = (screen->w_s * (double)x) / (WINDOW_WIDTH - 1)
		- screen->w_s / 2;
	screen->f_y = (-screen->h_s * (double)y) / (WINDOW_HEIGHT - 1)
		+ screen->h_s / 2;
}

/**
 * @brief Get the 3d coordinate object
 *
 * @param x
 * @param y
 * @return t_vector3d
 */
t_vector3d	get_camera_ray(int x, int y, t_global_data *data)
{
	t_vector3d	coordinate;

	coordinate.x = ((2.0 * x) / (WINDOW_WIDTH - 1.0)) - 1.0;
	coordinate.y = (-(2.0 * y) / (WINDOW_HEIGHT - 1.0)) + 1.0;
	coordinate.z = 0;
	return (vector3d_sub(coordinate, data->camera->coordinate));
}

t_vector3d	get_camera_ray_dynamic(int x, int y, t_global_data *data)
{
	t_vector3d		coordinate;
	t_screen_data	screen;
	t_vector3d		camera_dir;

	// if (_is_valid_vector(0, 0, 0, data->camera->direction))
	// 	return (get_camera_ray(x, y, data));
	// 0,0,0 はerror
	screen_data_init(x, y, data, &screen);
	camera_dir = vector3d_add(data->camera->coordinate,
			vector3d_fmulv(screen.camera_to_screen, data->camera->direction));
	coordinate = vector3d_add(vector3d_add(camera_dir,
				vector3d_fmulv(screen.f_x, screen.screen_unit_x)),
			vector3d_fmulv(screen.f_y, screen.screen_unit_y));
	return (vector3d_sub(coordinate, data->camera->coordinate));
}
