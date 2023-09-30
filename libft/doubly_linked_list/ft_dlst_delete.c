/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:46:20 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:32:58 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

void	ft_dlst_delete(t_dlist *target)
{
	if (target == NULL)
		return ;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	free(target->content);
	target->content = NULL;
	free(target);
	target = NULL;
	return ;
}
