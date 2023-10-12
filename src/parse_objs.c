/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:19:01 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/11 16:13:28 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**parse_sphere(const char *line)
{
	char	**info;
	size_t	i;

	i = 1;
	info = ft_split_charset(line, " ,\n");
	if (info == NULL)
		put_error("malloc");
	if (get_array_size(info) != ARR_SIZE_SP)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i]))
			return (free_char_array(info), NULL);
		i++;
	}
	if (!ft_isdouble(info[4]) || ft_atof(info[4]) <= 0.0)
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
		put_error("malloc");
	if (get_array_size(info) != ARR_SIZE_PL)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i]))
			return (free_char_array(info), NULL);
		i++;
	}
	if (!check_vector_valid(info, 4, 7))
		return (free_char_array(info), NULL);
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
		put_error("malloc");
	if (get_array_size(info) != ARR_SIZE_CY)
		return (free_char_array(info), NULL);
	while (i < 4)
	{
		if (!ft_isdouble(info[i++]))
			return (free_char_array(info), NULL);
	}
	if (!check_vector_valid(info, 4, 7))
		return (free_char_array(info), NULL);
	if (!ft_isdouble(info[7]) || !ft_isdouble(info[8])
		|| ft_atof(info[7]) <= 0.0 || ft_atof(info[8]) <= 0.0)
		return (free_char_array(info), NULL);
	if (!check_color_range(info, 9, 12))
		return (free_char_array(info), NULL);
	return (info);
}
