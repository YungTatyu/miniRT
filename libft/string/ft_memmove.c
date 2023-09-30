/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:57:26 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/20 09:57:26 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		tmp_d += (n - 1);
		tmp_s += (n - 1);
		while (n--)
			*tmp_d-- = *tmp_s--;
		return (dest);
	}
	else
	{
		while (n--)
			*tmp_d++ = *tmp_s++;
		return (dest);
	}
}
