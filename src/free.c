/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:42:27 by tterao            #+#    #+#             */
/*   Updated: 2023/10/10 09:49:24 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "objs.h"
#include <stdlib.h>

void	global_data_free(t_global_data *data)
{
	free(data->ambient_light);
	free(data->light);
	free(data->camera);
	objs_free(data->objs_list);
}

void	free_data_and_puterr(t_global_data *data, const char *message)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, message);
	ft_dprintf(STDERR_FILENO, "\n");
	global_data_free(data);
	exit(1);
}

void	free_char_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
