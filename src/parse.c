/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:35:48 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/14 14:30:33 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#define INVALID_ERR "Error\nInvalid format\n"

static void	_parse_to_init(t_global_data *data, const char **info)
{
	if (!ft_strcmp("A", info[0]))
	{
		if (data->ambient_light != NULL)
			return (free_data_and_puterr(data, "There are multiple A"));
		data->ambient_light = ambient_light_init(info);
	}
	else if (!ft_strcmp("C", info[0]))
	{
		if (data->camera != NULL)
			return (free_data_and_puterr(data, "There are multiple C"));
		data->camera = camera_init(info);
	}
	else if (!ft_strcmp("L", info[0]))
	{
		if (data->light != NULL)
			return (free_data_and_puterr(data, "There are multiple L"));
		data->light = light_init(info);
	}
	else if (!ft_strcmp("sp", info[0]))
		objs_addback(data->objs_list, objs_newnode(SPHERE, info));
	else if (!ft_strcmp("pl", info[0]))
		objs_addback(data->objs_list, objs_newnode(PLANE, info));
	else if (!ft_strcmp("cy", info[0]))
		objs_addback(data->objs_list, objs_newnode(CYLINDER, info));
}

static int	_parse_open(t_global_data *data, const char *file)
{
	size_t	i;
	int		fd;

	i = ft_strlen(file);
	if (i < 4)
		return (free_data_and_puterr(data, "Please input *.rt file."), -1);
	if (!ft_strncmp(".rt", &file[i - 3], 3) && file[i - 4] != '/')
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			return (free_data_and_puterr(data, strerror(errno)), -1);
		return (fd);
	}
	else
		return (free_data_and_puterr(data, "Please input *.rt file."), -1);
}

static void	_free_line_and_data(char *line, t_global_data *data)
{
	free(line);
	global_data_free(data);
	ft_dprintf(STDERR_FILENO, INVALID_ERR);
}

static bool	_parse_loop(t_global_data *data, int fd)
{
	char	*line;
	char	**info;
	size_t	count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!ft_strcmp("\n", line))
		{
			free(line);
			continue ;
		}
		info = parse_check(line, &count);
		if (info == NULL)
			return (_free_line_and_data(line, data), false);
		free(line);
		_parse_to_init(data, (const char **)info);
		free_char_array(info);
	}
	if (count == 0)
		return (free_data_and_puterr(data, "This is empty file."), false);
	return (true);
}

bool	parse(t_global_data *data, const char *file)
{
	int		fd;

	fd = _parse_open(data, file);
	if (fd == -1)
		return (false);
	if (!_parse_loop(data, fd))
		return (false);
	if (!check_exist_a_c_l(data))
		return (false);
	return (true);
}
