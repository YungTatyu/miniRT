/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:44:57 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/10 10:01:25 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	check_line(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			if (!ft_isdigit(line[i + 1]) && line[i + 1] != '-'
				&& line[i + 1] != '+')
				return (false);
		}
		else if (line[i] == ' ')
		{
			if (line[i + 1] == '\0' || line[i + 1] == '\n')
				return (true);
			if (line[i + 1] != ' ' && !ft_isdigit(line[i + 1])
				&& line[i + 1] != '-' && line[i + 1] != '+')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_exist_a_c_l(t_global_data *data)
{
	if (data->ambient_light == NULL)
		return (free_data_and_puterr(data, "A does not exist"), false);
	if (data->camera == NULL)
		return (free_data_and_puterr(data, "C does not exist"), false);
	if (data->light == NULL)
		return (free_data_and_puterr(data, "L does not exist"), false);
	return (true);
}

bool	check_vector_valid(char **info, size_t start, size_t end)
{
	size_t	i;
	bool	flag;

	i = start;
	flag = false;
	while (i < end)
	{
		if (!ft_isdouble(info[i])
			|| !check_range_float(ft_atof(info[i++]), -1.0, 1.0))
			return (false);
	}
	i = start;
	while (i < end)
	{
		if (ft_atof(info[i]) != 0.0f)
			flag = true;
		i++;
	}
	return (flag);
}

char	**parse_check(const char *line)
{
	if (!check_line(line))
		return (NULL);
	if (!ft_strncmp(MP_AMIBIENT_LIGHT, line, 2))
		return (parse_ambient_light(line));
	else if (!ft_strncmp(MP_CAMERA, line, 2))
		return (parse_camera(line));
	else if (!ft_strncmp(MP_LIGHT, line, 2))
		return (parse_light(line));
	else if (!ft_strncmp(MP_SPHERE, line, 3))
		return (parse_sphere(line));
	else if (!ft_strncmp(MP_PLANE, line, 3))
		return (parse_plane(line));
	else if (!ft_strncmp(MP_CYLINDER, line, 3))
		return (parse_cylinder(line));
	else
		return (NULL);
}
