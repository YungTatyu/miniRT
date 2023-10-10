/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:04:51 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/10 10:02:37 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**parse_ambient_light(const char *line)
{
	char	**info;

	info = ft_split_charset(line, " ,\n");
	if (!info)
		put_error("malloc");
	if (get_array_size(info) != ARR_SIZE_A)
		return (free_char_array(info), NULL);
	if (!ft_isdouble(info[1]))
		return (free_char_array(info), NULL);
	if (!check_range_float(ft_atof(info[1]), 0.0, 1.0))
		return (free_char_array(info), NULL);
	if (!check_color_range(info, 2, 5))
		return (free_char_array(info), NULL);
	return (info);
}

char	**parse_camera(const char *line)
{
	char	**info;
	size_t	i;

	i = 1;
	info = ft_split_charset(line, " ,\n");
	if (!info)
		put_error("malloc");
	if (get_array_size(info) != ARR_SIZE_C)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i]))
			return (free_char_array(info), NULL);
		i++;
	}
	if (!check_vector_valid(info, 4, 7))
		return (free_char_array(info), NULL);
	if (!ft_isint(info[7]) || !check_range_int(ft_atoi(info[7]), 0, 180)
		|| ft_atoi(info[7]) == 0)
		return (free_char_array(info), NULL);
	return (info);
}

char	**parse_light(const char *line)
{
	char	**info;
	size_t	i;

	i = 1;
	info = ft_split_charset(line, " ,\n");
	if (!info)
		put_error("malloc");
	if (get_array_size(info) != ARR_SIZE_L)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i]))
			return (free_char_array(info), NULL);
		i++;
	}
	if (!ft_isdouble(info[4]) || !check_range_float(ft_atof(info[4]), 0.0, 1.0))
		return (free_char_array(info), NULL);
	if (!check_color_range(info, 5, 8))
		return (free_char_array(info), NULL);
	return (info);
}
