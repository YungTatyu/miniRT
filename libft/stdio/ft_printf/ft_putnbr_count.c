/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:18:59 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 08:18:59 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n, int count)
{
	if (n < 0)
	{
		count = ft_putchar_count('-', count);
		if (n <= -10)
			count = ft_putnbr_count((n / -10), count);
		n = n % 10 * -1;
	}
	if (n >= 10)
		count = ft_putnbr_count(n / 10, count);
	count = ft_putchar_count((n % 10 + '0'), count);
	return (count);
}
