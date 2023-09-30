/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:50:32 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:12 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

void	ft_dlstadd_back(t_dlist *head, t_dlist *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->prev = head->prev;
	new->next = head;
	head->prev->next = new;
	head->prev = new;
	return ;
}
