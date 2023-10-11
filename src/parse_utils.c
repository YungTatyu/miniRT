/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:35:48 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/11 16:10:47 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	check_range_float(double num, double min, double max)
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
