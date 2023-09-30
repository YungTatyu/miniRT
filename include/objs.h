/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:27:32 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 14:34:27 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJS_H
# define OBJS_H

enum e_obj_type
{
	HEAD,
	PALNE,
	SPHERE,
	CYLINDER,
};

typedef struct s_objs
{
	e_obj_type		type;
	void			*obj;
	struct s_objs	*next;
}t_objs;

t_objs	*objs_newnode(e_obj_type type, const char **info);
t_objs	*objs_addback(t_objs **head, t_objs *newnode);
t_objs	*objs_lastnode(t_objs **head);
t_objs	*objs_free(t_objs **head);

#endif
