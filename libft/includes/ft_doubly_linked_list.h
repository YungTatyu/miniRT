/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_linked_list.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:41:06 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:35:31 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLY_LINKED_LIST_H
# define FT_DOUBLY_LINKED_LIST_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

void	ft_dlst_delete(t_dlist *target);
void	ft_dlst_free_all(t_dlist *head);
t_dlist	*ft_dlst_head_init(void);
void	ft_dlstadd_back(t_dlist *head, t_dlist *new_node);
void	ft_dlstadd_front(t_dlist *head, t_dlist *new_node);
void	ft_dlstinsert_back(t_dlist *target, t_dlist *new_node);
void	ft_dlstinsert_front(t_dlist *target, t_dlist *new_node);
t_dlist	*ft_dlstnew(void *content);
int		ft_dlstsize(t_dlist *head);

#endif