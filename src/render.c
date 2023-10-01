
#include "miniRT.h"
#include "parse.h"
#include <mlx.h>

void	_mlx_init(t_global_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->height,
			data->width, "miniRT");
	data->img = mlx_new_image(data->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_global_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render(t_global_data *data)
{
	_mlx_init(data);
	my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx);
}
