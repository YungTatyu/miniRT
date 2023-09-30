/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:54:04 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 19:01:11 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
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
	t_global_data	*data;

	data = NULL;
	if (argc == 2)
	{
		parse(data, argv[1]);
	}
	else
		ft_dprintf(STDERR_FILENO, "Error\nInvalid number of arguments\n");
	return (0);
}
