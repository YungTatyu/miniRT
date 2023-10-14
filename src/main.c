/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:54:04 by tterao            #+#    #+#             */
/*   Updated: 2023/10/14 15:01:00 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_global_data	data;

	if (argc == 2)
	{
		global_data_init(&data);
		if (!parse(&data, argv[1]))
			return (1);
		render(&data);
	}
	else
		ft_dprintf(STDERR_FILENO, "Error\nInvalid number of arguments\n");
	return (0);
}

// __attribute__((destructor))
// 	static void	destructor(void) {
// 	system("leaks -q miniRT");
// }
