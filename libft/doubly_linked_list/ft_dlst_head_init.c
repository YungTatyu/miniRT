/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_head_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:11 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:08 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

t_dlist	*ft_dlst_head_init(void)
{
	t_dlist	*head;

	head = ft_dlstnew(NULL);
	if (head == NULL)
		return (NULL);
	head->prev = head;
	head->next = head;
	return (head);
}
