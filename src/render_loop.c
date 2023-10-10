
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
 * @return float
 */
static float	_get_t_obj(float current_t, float t, t_objs *node, t_objs **obj)
{
	if (t < 0.0f)
		return (current_t);
	else if (current_t < 0.0f || fminf(current_t, t) == t)
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
 * @return float
 */
float	hit_object(t_vector3d start_pos, t_objs *head, t_vector3d ray, t_objs **obj)
{
	float	t;
	t_objs	*node;

	node = head->next;
	t = -1.0f;
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

void	render_loop(t_global_data *data)
{
	t_vector2d	pos;
	t_vector3d	camera_ray;
	float		t;
	t_objs		*obj;
	t_fcolor	radiance;

	pos.y = 0;
	while (pos.y < WINDOW_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WINDOW_WIDTH)
		{
			camera_ray = get_camera_ray_dynamic(pos.x, pos.y, data);
			t = hit_object(data->camera->coordinate, data->objs_list, get_camera_ray_dynamic(pos.x, pos.y, data), &obj);
			// printf("t=%f\n", t);
			if (t >= 0.0f)
			{
				radiance = get_radiance(data, obj, camera_ray, t);
				my_mlx_pixel_put(data, pos.x, pos.y, create_rgb(radiance.red, radiance.green, radiance.blue));
				// my_mlx_pixel_put(data, pos.x, pos.y, create_rgb(objs_get_color(obj).red, objs_get_color(obj).green, objs_get_color(obj).blue));
			}
			else
				my_mlx_pixel_put(data, pos.x, pos.y, create_rgb(data->background.red, data->background.green, data->background.blue));
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
