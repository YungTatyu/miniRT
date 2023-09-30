/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:13:07 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 14:20:55 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include <limits.h>
# include <stddef.h>
# include "ft_stdlib.h"

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isdouble(char *s);
int	ft_isint(char *s);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif