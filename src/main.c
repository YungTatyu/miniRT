/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:54:04 by tterao            #+#    #+#             */
/*   Updated: 2023/09/29 19:53:44 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdlib.h>
#include <mlx.h>

typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
	int		screen_width;
	int		screen_height;
}t_screen;


int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (EXIT_FAILURE);
	(void)argv;
	t_screen data;
	data.mlx = mlx_init();
	data.screen_height = 1920;
	data.screen_width = 1080;
	data.mlx_win = mlx_new_window(data.mlx, data.screen_height, data.screen_width, "test");
	while (1)
	{
		;
	}

	return (0);
}
