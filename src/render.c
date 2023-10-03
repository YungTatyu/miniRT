
#include "miniRT.h"
#include "parse.h"
#include <mlx.h>

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

t_vector3d	get_3d_coordinate(int x, int y)
{
	t_vector3d	coordinate;

	coordinate.x = ((2 * x) / (WINDOW_WIDTH - 1)) - 1;
	coordinate.y = ((-2 * y) / (WINDOW_HEIGHT - 1)) + 1;
	coordinate.z = 0;
	return (coordinate);
}

float	hit_squere(t_vector3d ray, t_vector3d camera_p,
						t_vector3d obj_p, t_vector3d obj_direction)
{
	float	t;

	t = -1.0f * (vector3d_dot_product(
				vector3d_sub(camera_p, obj_p),
				obj_direction))
		/ vector3d_dot_product(ray, obj_direction);
	return (t);
}

void	render_loop(t_global_data *data)
{
	int			y;
	int			x;
	t_vector3d	coordinate;
	t_vector3d	camera_ray;
	const t_plane	*plane = data->objs_list->next->obj;
	float	t;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate(x, y);
			camera_ray = vector3d_sub(coordinate, data->camera->coordinate);
			t = hit_squere(camera_ray, data->camera->coordinate, plane->coordinate, plane->direction);
			if (t >= 0.0f)
				my_mlx_pixel_put(data, x, y, create_rgb(plane->red, plane->green, plane->blue));
			else
				my_mlx_pixel_put(data, x, y, create_rgb(data->light->red, data->light->green, data->light->blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	render(t_global_data *data)
{
	_mlx_init(data);
	render_loop(data);
	mlx_loop(data->mlx);
}
