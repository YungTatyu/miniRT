/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:38:20 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 17:00:58 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

t_ambient_lightning	*ambient_light_init(const char **info)
{
	t_ambient_lightning	*ambient_light;

	ambient_light = ft_calloc(sizeof(t_ambient_lightning), 1);
	ambient_light->ratio = ft_atof(*(info++));
	ambient_light->red = ft_atoi(*(info++));
	ambient_light->green = ft_atoi(*(info++));
	ambient_light->blue = ft_atoi(*(info++));
	return (ambient_light);
}

t_camera	*camera_init(const char **info)
{
	t_camera	*camera;

	camera = ft_calloc(sizeof(t_camera), 1);
	camera->x = ft_atof(*(info++));
	camera->y = ft_atof(*(info++));
	camera->z = ft_atof(*(info++));
	camera->x_axis = ft_atof(*(info++));
	camera->y_axis = ft_atof(*(info++));
	camera->z_axis = ft_atof(*(info++));
	return (camera);
}

t_light	*light_init(const char **info)
{
	t_light	*light;

	light = ft_calloc(sizeof(t_light), 1);
	light->x = ft_atof(*(info++));
	light->y = ft_atof(*(info++));
	light->z = ft_atof(*(info++));
	light->ratio = ft_atof(*(info++));
	light->red = ft_atoi(*(info++));
	light->green = ft_atoi(*(info++));
	light->blue = ft_atoi(*(info++));
	return (light);
}

void	global_data_init(t_global_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->height = WINDOW_HEIGHT;
	data->width = WINDOW_WIDTH;
	data->ambient_light = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->objs_list = NULL;
}
