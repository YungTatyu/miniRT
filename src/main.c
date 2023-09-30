/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:54:04 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 14:45:45 by tterao           ###   ########.fr       */
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
	
	return (0);
}
