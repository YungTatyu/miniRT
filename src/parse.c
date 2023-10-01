/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:35:48 by ryhara            #+#    #+#             */
/*   Updated: 2023/10/01 15:34:01 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	_print_char_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s ", array[i]);
		i++;
	}
	ft_printf("\n");
}

static char	**_parse_check(const char *line)
{
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

// init 失敗時にエラーにした方が良いので返り値は変わるかもしれないです
static void	_parse_to_init(t_global_data *data, const char **info)
{
	if (!ft_strcmp("A", info[0]))
		data->ambient_light = ambient_light_init(info);
	else if (!ft_strcmp("C", info[0]))
		data->camera = camera_init(info);
	else if (!ft_strcmp("L", info[0]))
		data->light = light_init(info);
	else if (!ft_strcmp("sp", info[0]))
		objs_addback(data->objs_list, objs_newnode(SPHERE, info));
	else if (!ft_strcmp("pl", info[0]))
		objs_addback(data->objs_list, objs_newnode(PLANE, info));
	else if (!ft_strcmp("cy", info[0]))
		objs_addback(data->objs_list, objs_newnode(CYLINDER, info));
	else
		ft_dprintf(STDERR_FILENO, "Error\n");
}

static int	parse_open(const char *file)
{
	size_t	i;
	int		fd;

	i = ft_strlen(file);
	if (i < 4)
	{
		ft_dprintf(STDERR_FILENO, "Error\nPlease input *.rt file.\n");
		return (-1);
	}
	if (!ft_strncmp(".rt", &file[i - 3], 3))
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
			perror("open");
			return (-1);
		}
		return (fd);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "Error\nPlease input *.rt file.\n");
		return (-1);
	}
}

bool	parse(t_global_data *data, const char *file)
{
	int		fd;
	char	*line;
	char	**info;

	fd = parse_open(file);
	if (fd == -1)
		return (false);
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
		info = _parse_check(line);
		if (info == NULL)
		{
			free(line);
			// free data all
			ft_dprintf(STDERR_FILENO, "Error\nInvalid format\n");
			return (false);
		}
		free(line);
		_parse_to_init(data, (const char **)info);
		_print_char_array(info);
		free_char_array(info);
	}
	return (true);
}
