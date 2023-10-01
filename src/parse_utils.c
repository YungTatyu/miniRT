/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:35:48 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/30 18:00:03 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	check_range_float(float num, float min, float max)
{
	if (num >= min && num <= max)
		return (true);
	else
		return (false);
}

bool	check_range_int(int num, int min, int max)
{
	if (num >= min && num <= max)
		return (true);
	else
		return (false);
}

size_t	get_array_size(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
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

bool	check_color_range(char **info, size_t start, size_t end)
{
	size_t	i;

	i = start;
	while (i < end)
	{
		if (!ft_isint(info[i])
			|| !check_range_int(ft_atoi(info[i]), 0, 255))
			return (false);
		i++;
	}
	return (true);
}
