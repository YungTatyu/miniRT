/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:59:20 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 17:41:41 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "miniRT.h"

# define WINDOW_HEIGHT 1200
# define WINDOW_WIDTH 1000
# define MP_AMIBIENT_LIGHT "A "
# define MP_CAMERA "C "
# define MP_LIGHT "L "
# define MP_SPHERE "sp "
# define MP_PLANE "pl "
# define MP_CYLINDER "cy "

# include <stdbool.h>

void				global_data_init(t_global_data *data);
void				global_data_free(t_global_data *data);
bool				parse(t_global_data *data, const char *file);
t_ambient_lightning	*ambient_light_init(const char **info);
t_camera			*camera_init(const char **info);
t_light				*light_init(const char **info);
bool				parse_ambient_light(const char *line);
bool				parse_camera(const char *line);

#endif
