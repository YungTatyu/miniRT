/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_free_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:48:05 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:02 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

void	ft_dlst_free_all(t_dlist *head)
{
	t_dlist	*tmp;
	t_dlist	*delete;

	if (head == NULL)
		return ;
	tmp = head->next;
	while (tmp != head)
	{
		delete = tmp;
		tmp = tmp->next;
		ft_dlst_delete(delete);
	}
	free(head->content);
	head->content = NULL;
	free(head);
	head = NULL;
	return ;
}
