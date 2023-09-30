/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:52:49 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:32 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

void	ft_dlstinsert_back(t_dlist *target, t_dlist *new)
{
	if (target == NULL || new == NULL)
		return ;
	new->prev = target;
	new->next = target->next;
	target->next->prev = new;
	target->next = new;
	return ;
}
