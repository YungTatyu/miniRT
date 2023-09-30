/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:35:48 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/30 19:01:31 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_char_array(char **array)
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

static char	**parse_check(const char *line)
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
static void	parse_to_init(t_global_data *data, char **info)
{
	if (!ft_strcmp("A", info[0]))
		return ;
	else if (!ft_strcmp("C", info[0]))
		return ;
	else if (!ft_strcmp("L", info[0]))
		return ;
	else if (!ft_strcmp("sp", info[0]))
		return ;
	else if (!ft_strcmp("pl", info[0]))
		return ;
	else if (!ft_strcmp("cy", info[0]))
		return ;
	else
		ft_dprintf(STDERR_FILENO, "Error\n");
}

bool	parse(t_global_data *data, const char *file)
{
	int		fd;
	char	*line;
	char	**info;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		perror("open");
		return (false);
	}
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
		info = parse_check(line);
		if (info == NULL)
		{
			free(line);
			// free data all
			ft_dprintf(STDERR_FILENO, "Error\nInvalid format\n");
			return (false);
		}
		free(line);
		parse_to_init(data, info);
		print_char_array(info);
		free_char_array(info);
	}
	return (true);
}