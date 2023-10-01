/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:50 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/06 12:45:50 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>
# include "../../includes/ft_string.h"

int		ft_printf(const char *s, ...);
int		ft_putnbr_count(int n, int count);
int		ft_putchar_count(char c, int count);
int		ft_putstr_count(char *s, int count);
int		ft_putui_count(unsigned int num, int count);
int		ft_putnbr_base(unsigned long n, char *base, int count);
int		ft_putaddress(unsigned long n, char *base, int count);

#endif