/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:14:48 by tterao            #+#    #+#             */
/*   Updated: 2023/10/11 16:25:34 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include "vector3d.h"
#include <mlx.h>
#include <math.h>

/**
 * @brief rayに一番近いオブジェクトとそれのtを取得する
 *
 * @param current_t
 * @param t
 * @param node
 * @param obj
 * @return double
 */
static double	_get_t_obj(double current_t, double t,
						t_objs *node, t_objs **obj)
{
	if (t < 0.0)
		return (current_t);
	else if (current_t < 0.0 || fmin(current_t, t) == t)
	{
		*obj = node;
		return (t);
	}
	return (current_t);
}

/**
 * @brief objのタイプに対応したオブジェクトの関数を呼ぶ
 *
 * @param data
 * @param head
 * @param ray
 * @param obj
 * @return double
 */
double	hit_object(t_vector3d start_pos, t_objs *head,
					t_vector3d ray, t_objs **obj)
{
	double	t;
	t_objs	*node;

	node = head->next;
	t = -1.0;
	while (node != head)
	{
		if (node->type == PLANE)
			t = _get_t_obj(t, hit_plane(ray, start_pos,
						objs_get_coordinate(node),
						((t_plane *)node->obj)->direction), node, obj);
		else if (node->type == SPHERE)
			t = _get_t_obj(t, hit_sphere(ray, start_pos,
						objs_get_coordinate(node),
						((t_sphere *)node->obj)->radius), node, obj);
		else if (node->type == CYLINDER)
			t = _get_t_obj(t, hit_cylinder(ray, start_pos,
						(t_cylinder *)node->obj), node, obj);
		node = node->next;
	}
	return (t);
}

static void	_put_pixel(t_global_data *data, t_vector3d ray, t_vector2d pos)
{
	t_objs			*obj;
	const double	t = hit_object(data->camera->coordinate,
			data->objs_list, ray, &obj);
	t_fcolor		radiance;

	if (t >= 0.0)
	{
		radiance = get_radiance(data, obj, ray, t);
		my_mlx_pixel_put(data, pos.x, pos.y,
			create_rgb(radiance.red, radiance.green, radiance.blue));
	}
	else
		my_mlx_pixel_put(data, pos.x, pos.y,
			create_rgb(data->background.red, data->background.green,
				data->background.blue));
}

void	render_loop(t_global_data *data)
{
	t_vector2d	pos;
	t_vector3d	camera_ray;

	pos.y = 0;
	while (pos.y < WINDOW_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WINDOW_WIDTH)
		{
			camera_ray = get_camera_ray_dynamic(pos.x, pos.y, data);
			_put_pixel(data, camera_ray, pos);
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
