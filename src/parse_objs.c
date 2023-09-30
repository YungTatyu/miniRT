/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:19:01 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/30 18:02:10 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**parse_sphere(const char *line)
{
	char	**info;
	size_t	i;

	i = 1;
	info = ft_split_charset(line, " ,\n");
	if (!info)
		return (NULL);
	if (get_array_size(info) != 8)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i]))
			return (free_char_array(info), NULL);
		i++;
	}
	if (!ft_isdouble(info[4]))
		return (free_char_array(info), NULL);
	if (!check_color_range(info, 5, 8))
		return (free_char_array(info), NULL);
	return (info);
}

char	**parse_plane(const char *line)
{
	char	**info;
	size_t	i;

	i = 1;
	info = ft_split_charset(line, " ,\n");
	if (!info)
		return (NULL);
	if (get_array_size(info) != 10)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i]))
			return (free_char_array(info), NULL);
		i++;
	}
	while (i < 7)
	{
		if (!ft_isdouble(info[i])
			|| !check_range_float(ft_atof(info[i]), -1.0, 1.0))
			return (free_char_array(info), NULL);
		i++;
	}
	if (!check_color_range(info, 7, 10))
		return (free_char_array(info), NULL);
	return (info);
}

char	**parse_cylinder(const char *line)
{
	char	**info;
	size_t	i;

	i = 1;
	info = ft_split_charset(line, " ,\n");
	if (!info)
		return (NULL);
	if (get_array_size(info) != 12)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i++]))
			return (free_char_array(info), NULL);
	}
	while (i < 7)
	{
		if (!ft_isdouble(info[i])
			|| !check_range_float(ft_atof(info[i++]), -1.0, 1.0))
			return (free_char_array(info), NULL);
	}
	if (!ft_isdouble(info[7]) || !ft_isdouble(info[8]))
		return (free_char_array(info), NULL);
	if (!check_color_range(info, 9, 12))
		return (free_char_array(info), NULL);
	return (info);
}
