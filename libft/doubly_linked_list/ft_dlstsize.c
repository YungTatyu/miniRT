/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:52:07 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:45 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_doubly_linked_list.h"

int	ft_dlstsize(t_dlist *head)
{
	int		size;
	t_dlist	*current;

	if (head == NULL)
		return (0);
	size = 0;
	current = head->next;
	while (current != head)
	{
		size++;
		current = current->next;
	}
	return (size);
}
