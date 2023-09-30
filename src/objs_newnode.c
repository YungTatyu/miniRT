/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_newnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:13:00 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 16:32:42 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "objs.h"
#include "libft.h"

static t_plane	*_plane_newnode(const char **info)
{
	t_plane	*newnode;

	newnode = ft_calloc(sizeof(t_plane), 1);
	newnode->x = ft_atof(*(info++));
	newnode->y = ft_atof(*(info++));
	newnode->z = ft_atof(*(info++));
	newnode->x_axis = ft_atof(*(info++));
	newnode->y_axis = ft_atof(*(info++));
	newnode->z_axis = ft_atof(*(info++));
	newnode->red = ft_atoi(*(info++));
	newnode->green = ft_atoi(*(info++));
	newnode->blue = ft_atoi(*(info++));
	return (newnode);
}

static t_sphere	*_sphere_newnode(const char **info)
{
	t_sphere	*newnode;

	newnode = ft_calloc(sizeof(t_sphere), 1);
	newnode->x = ft_atof(*(info++));
	newnode->y = ft_atof(*(info++));
	newnode->z = ft_atof(*(info++));
	newnode->diameter = ft_atof(*(info++));
	newnode->radius = newnode->diameter / (float)2.0;
	newnode->red = ft_atoi(*(info++));
	newnode->green = ft_atoi(*(info++));
	newnode->blue = ft_atoi(*(info++));
	return (newnode);
}

static t_cylinder	*_cylinder_newnode(const char **info)
{
	t_cylinder	*newnode;

	newnode = ft_calloc(sizeof(t_cylinder), 1);
	newnode->x = ft_atof(*(info++));
	newnode->y = ft_atof(*(info++));
	newnode->z = ft_atof(*(info++));
	newnode->x_axis = ft_atof(*(info++));
	newnode->y_axis = ft_atof(*(info++));
	newnode->z_axis = ft_atof(*(info++));
	newnode->diameter = ft_atof(*(info++));
	newnode->radius = newnode->diameter / (float)2.0;
	newnode->red = ft_atoi(*(info++));
	newnode->green = ft_atoi(*(info++));
	newnode->blue = ft_atoi(*(info++));
	return (newnode);
}

t_objs	*objs_newnode(enum e_obj_type type, const char **info)
{
	t_objs	*newnode;

	newnode = ft_calloc(sizeof(t_objs), 1);
	newnode->type = type;
	newnode->next = NULL;
	if (type == HEAD)
		newnode->obj = NULL;
	else if (type == PLANE)
		newnode->obj = (void *)_plane_newnode(info);
	else if (type == SPHERE)
		newnode->obj = (void *)_sphere_newnode(info);
	else if (type == CYLINDER)
		newnode->obj = (void *)_cylinder_newnode(info);
	return (newnode);
}
