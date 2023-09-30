/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:12:14 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/31 10:12:14 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_singly_linked_list.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst == NULL || new_node == NULL)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}
