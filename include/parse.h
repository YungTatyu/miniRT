/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:59:20 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 18:48:50 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "miniRT.h"
# include "../libft/includes/libft.h"
# include "../libft/stdio/ft_printf/ft_printf.h"
# include "../libft/stdio/ft_dprintf/ft_dprintf.h"

# define WINDOW_HEIGHT 1200
# define WINDOW_WIDTH 1000
# define MP_AMIBIENT_LIGHT "A "
# define MP_CAMERA "C "
# define MP_LIGHT "L "
# define MP_SPHERE "sp "
# define MP_PLANE "pl "
# define MP_CYLINDER "cy "

# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

void				global_data_init(t_global_data *data);
bool				parse(t_global_data *data, const char *file);
t_ambient_lightning	*ambient_light_init();
t_camera			*camera_init();
t_light				*light_init();

char				**parse_ambient_light(const char *line);
char				**parse_camera(const char *line);
char				**parse_light(const char *line);
char				**parse_sphere(const char *line);
char				**parse_plane(const char *line);
char				**parse_cylinder(const char *line);

bool				check_range_float(float num, float min, float max);
bool				check_range_int(int num, int min, int max);
size_t				get_array_size(char **array);
void				free_char_array(char **array);
bool				check_color_range(char **info, size_t start, size_t end);
#endif
