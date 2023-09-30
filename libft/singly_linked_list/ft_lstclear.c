/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:48:34 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/03 11:48:34 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_singly_linked_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*lst_del;

	lst_tmp = *lst;
	if (lst == NULL || del == NULL)
		return ;
	while (lst_tmp != NULL)
	{
		lst_del = lst_tmp;
		lst_tmp = lst_tmp -> next;
		ft_lstdelone(lst_del, del);
	}
	*lst = NULL;
}
