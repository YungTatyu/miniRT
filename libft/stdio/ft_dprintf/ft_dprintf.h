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

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_dprintf(int fd, const char *s, ...);
int		ft_dputnbr(int fd, int n, int count);
int		ft_dputchar(int fd, char c, int count);
int		ft_dputstr(int fd, char *s, int count);
int		ft_dputui(int fd, unsigned int num, int count);
int		ft_dputnbr_base(int fd, unsigned long n, char *base, int count);
int		ft_dputaddress(int fd, unsigned long n, char *base, int count);
size_t	ft_strlen(const char *s);

#endif