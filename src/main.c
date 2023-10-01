/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:54:04 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 17:44:15 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include <stdlib.h>
#include <mlx.h>

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
