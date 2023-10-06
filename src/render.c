
#include "miniRT.h"
#include "parse.h"
#include <mlx.h>
#include <math.h>

void	render_sphere_loop(t_global_data *data, t_sphere *sphere);

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

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/**
 * @brief Get the 3d coordinate object
 *
 * @param x
 * @param y
 * @return t_vector3d
 */
t_vector3d	get_3d_coordinate(int x, int y)
{
	t_vector3d	coordinate;

	coordinate.x = ((2.0f * x) / (WINDOW_WIDTH - 1.0f)) - 1.0f;
	coordinate.y = (-(2.0f * y) / (WINDOW_HEIGHT - 1.0f)) + 1.0f;
	coordinate.z = 0;
	return (coordinate);
}

/**
 * @brief 平面とレイの交差判定をおこなう
 *
 * @param ray
 * @param camera_pos
 * @param obj_pos
 * @param obj_dir
 * @return float t cameraからobjectまでの距離のベクトルの大きさを示すtが返す
 */
float	hit_plane(t_vector3d ray, t_vector3d camera_pos,
						t_vector3d obj_pos, t_vector3d obj_dir)
{
	float	t;

	t = -1.0f * (vector3d_dot(
				vector3d_sub(camera_pos, obj_pos),
				obj_dir))
		/ vector3d_dot(ray, obj_dir);
	//分母が0の場合、t = nan になる
	if (isnan(t))
		t = -1.0f;
	return (t);
}

void	render_plane_loop(t_global_data *data, t_plane *plane)
{
	int			y;
	int			x;
	t_vector3d	coordinate;
	t_vector3d	camera_ray;
	float	t;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate(x, y);
			camera_ray = vector3d_sub(coordinate, data->camera->coordinate);
			t = hit_plane(camera_ray, data->camera->coordinate, plane->coordinate, plane->direction);
			// printf("t=%f\n", t);
			if (t >= 0.0f)
				my_mlx_pixel_put(data, x, y, create_rgb(plane->red, plane->green, plane->blue));
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->background.red, data->background.green, data->background.blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	render(t_global_data *data)
{
	t_objs	*node;

	_mlx_init(data);
	node = data->objs_list->next;
	while (node->type != HEAD)
	{
		if (node->type == PLANE)
			render_plane_loop(data, (t_plane *)node->obj);
		else if (node->type == SPHERE)
			render_sphere_loop(data, (t_sphere *)node->obj);
		node = node->next;
	}
	mlx_loop(data->mlx);
}
