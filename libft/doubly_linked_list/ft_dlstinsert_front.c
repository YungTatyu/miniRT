/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:56:09 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:36 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

void	ft_dlstinsert_front(t_dlist *target, t_dlist *new)
{
	if (target == NULL || new == NULL)
		return ;
	new->prev = target->prev;
	new->next = target;
	target->prev->next = new;
	target->prev = new;
	return ;
}
