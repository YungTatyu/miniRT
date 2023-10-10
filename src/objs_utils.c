/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:42:57 by tterao            #+#    #+#             */
/*   Updated: 2023/10/09 17:17:37 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "objs.h"
#include <unistd.h>
#include <stddef.h>

t_objs	*objs_lastnode(t_objs *head)
{
	t_objs	*node;

	node = head->next;
	while (node->next != head)
		node = node->next;
	return (node);
}

void	objs_addback(t_objs *head, t_objs *newnode)
{
	t_objs	*lastnode;

	lastnode = objs_lastnode(head);
	lastnode->next = newnode;
	newnode->next = head;
}

void	objs_free(t_objs *head)
{
	t_objs	*node;
	t_objs	*tmp;

	node = head->next;
	while (node != head)
	{
		tmp = node;
		node = node->next;
		free(tmp->obj);
		free(tmp);
	}
	free(head);
}

t_vector3d	objs_get_coordinate(const t_objs *node)
{
	if (node->type == PLANE)
		return (((t_plane *)node->obj)->coordinate);
	else if (node->type == SPHERE)
		return (((t_sphere *)node->obj)->coordinate);
	// else if (node->type == CYLINDER)
	return (((t_cylinder *)node->obj)->coordinate);
}

t_color	objs_get_color(const t_objs *node)
{
	if (node->type == PLANE)
		return (((t_plane *)node->obj)->color);
	else if (node->type == SPHERE)
		return (((t_sphere *)node->obj)->color);
	// else if (node->type == CYLINDER)
	return (((t_cylinder *)node->obj)->color);
}
