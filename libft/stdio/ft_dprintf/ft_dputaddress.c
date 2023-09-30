/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:44:38 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/13 17:44:38 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputaddress(int fd, unsigned long n, char *base, int count)
{
	count = ft_dputstr(fd, "0x", count);
	count = ft_dputnbr_base(fd, n, base, count);
	return (count);
}
