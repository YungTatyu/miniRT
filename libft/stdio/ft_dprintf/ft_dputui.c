/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:41:40 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/07 12:41:40 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputui(int fd, unsigned int n, int count)
{
	if (n >= 10)
		count = ft_dputui(fd, n / 10, count);
	count = ft_dputchar(fd, (n % 10 + '0'), count);
	return (count);
}
