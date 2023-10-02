
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

void	render_loop(t_global_data *data)
{
	int			y;
	int			x;
	t_vector3d	coordinate;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			coordinate = get_3d_coordinate(x, y);
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
