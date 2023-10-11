/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:59:20 by tterao            #+#    #+#             */
/*   Updated: 2023/10/11 16:33:30 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_H
# define PARSE_H

# include "miniRT.h"
# include "libft.h"
# include "ft_printf.h"
# include "ft_dprintf.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

# define WINDOW_HEIGHT 800.0
# define WINDOW_WIDTH 800.0
# define MP_AMIBIENT_LIGHT "A "
# define MP_CAMERA "C "
# define MP_LIGHT "L "
# define MP_SPHERE "sp "
# define MP_PLANE "pl "
# define MP_CYLINDER "cy "
# define ARR_SIZE_A 5
# define ARR_SIZE_C 8
# define ARR_SIZE_L 8
# define ARR_SIZE_SP 8
# define ARR_SIZE_PL 10
# define ARR_SIZE_CY 12

// error.c
void				put_error(const char *name);
// free.c
void				global_data_free(t_global_data *data);
void				free_data_and_puterr(t_global_data *data,
						const char *message);
void				free_char_array(char **array);
// init.c
void				global_data_init(t_global_data *data);
t_ambient_lightning	*ambient_light_init(const char **info);
t_camera			*camera_init(const char **info);
t_light				*light_init(const char **info);
// parse_check.c
bool				check_line(const char *line);
bool				check_exist_a_c_l(t_global_data *data);
bool				check_vector_valid(char **info, size_t start, size_t end);
char				**parse_check(const char *line);
// parse_objs.c
char				**parse_sphere(const char *line);
char				**parse_plane(const char *line);
char				**parse_cylinder(const char *line);
// parse_settings.c
char				**parse_ambient_light(const char *line);
char				**parse_camera(const char *line);
char				**parse_light(const char *line);
// parse_utils.c
bool				check_range_float(double num, double min, double max);
bool				check_range_int(int num, int min, int max);
size_t				get_array_size(char **array);
bool				check_color_range(char **info, size_t start, size_t end);
// parse.c
bool				parse(t_global_data *data, const char *file);

#endif
