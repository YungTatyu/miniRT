/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:27:32 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 15:57:04 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJS_H
# define OBJS_H

enum e_obj_type
{
	HEAD,
	PLANE,
	SPHERE,
	CYLINDER,
};

typedef struct s_objs
{
	enum e_obj_type		type;
	void				*obj;
	struct s_objs		*next;
}t_objs;

t_objs	*objs_newnode(enum e_obj_type type, const char **info);
void	objs_addback(t_objs *head, t_objs *newnode);
t_objs	*objs_lastnode(t_objs *head);
void	objs_free(t_objs *head);

#endif
