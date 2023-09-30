/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:42:57 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 16:38:13 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <unistd.h>

t_objs	*objs_lastnode(t_objs *head)
{
	t_objs	*node;

	node = head;
	while (node->next != NULL)
	{
		if ((node->next)->type == HEAD)
			break ;
		node = node->next;
	}
	return (node);
}

void	objs_addback(t_objs *head, t_objs *newnode)
{
	t_objs	*lastnode;

	lastnode = objs_lastnode(head);
	lastnode->next = newnode;
	newnode->next = head;
}
