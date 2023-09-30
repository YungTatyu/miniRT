/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:23:39 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 21:23:39 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ans;

	ans = (unsigned char *)s;
	while (n--)
	{
		*ans = (unsigned char)c;
		ans++;
	}
	return (s);
}
