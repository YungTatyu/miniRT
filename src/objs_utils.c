/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:42:57 by tterao            #+#    #+#             */
/*   Updated: 2023/10/08 17:22:35 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
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
