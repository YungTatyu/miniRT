/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:27:32 by tterao            #+#    #+#             */
/*   Updated: 2023/10/11 16:12:29 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJS_H
# define OBJS_H

# include "miniRT.h"
# include "vector3d.h"

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

typedef struct s_color	t_color;

t_objs		*objs_newnode(enum e_obj_type type, const char **info);
void		objs_addback(t_objs *head, t_objs *newnode);
t_objs		*objs_lastnode(t_objs *head);
void		objs_free(t_objs *head);
t_vector3d	objs_get_coordinate(const t_objs *node);
t_color		objs_get_color(const t_objs *node);


#endif
