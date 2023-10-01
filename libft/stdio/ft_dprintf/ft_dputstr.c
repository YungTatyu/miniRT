/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:12:21 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 08:12:21 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputstr(int fd, char *s, int count)
{
	if (s == NULL)
	{
		count = ft_dputstr(fd, "(null)", count);
		return (count);
	}
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}
