/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:42:18 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:18 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static	int	check_print(int fd, char *str, va_list args, int count)
{
	char	*baselow;
	char	*baseup;

	baselow = "0123456789abcdef";
	baseup = "0123456789ABCDEF";
	if (*str == 'd' || *str == 'i')
		count = ft_dputnbr(fd, va_arg(args, int), count);
	else if (*str == 'c')
		count = ft_dputchar(fd, va_arg(args, int), count);
	else if (*str == 's')
		count = ft_dputstr(fd, va_arg(args, char *), count);
	else if (*str == 'u')
		count = ft_dputui(fd, va_arg(args, unsigned int), count);
	else if (*str == 'x')
		count = ft_dputnbr_base(fd, va_arg(args, unsigned int), baselow, count);
	else if (*str == 'X')
		count = ft_dputnbr_base(fd, va_arg(args, unsigned int), baseup, count);
	else if (*str == 'p')
		count = ft_dputaddress(fd, va_arg(args, unsigned long), baselow, count);
	else if (*str == '%')
		count = ft_dputchar(fd, '%', count);
	else
		return (-1);
	return (count);
}

static int	check_error(int fd, const char *s)
{
	if (fd < 0)
		return (-1);
	if (s == NULL)
		return (-1);
	return (0);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		count;
	char	*str;

	count = 0;
	if (check_error(fd, s) < 0)
		return (-1);
	str = (char *)s;
	va_start(args, s);
	while (*str)
	{
		if (*str == '%')
		{
			count = check_print(fd, ++str, args, count);
			if (count < 0)
				return (-1);
			str++;
		}
		else
			count = ft_dputchar(fd, *str++, count);
		if (count < 0)
			return (-1);
	}
	va_end(args);
	return (count);
}
