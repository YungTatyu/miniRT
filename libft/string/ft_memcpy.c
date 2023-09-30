/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:46:02 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/20 09:46:02 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	i = 0;
	cpy = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*cpy = *((unsigned char *)src);
		cpy++;
		src++;
		i++;
	}
	return (dest);
}
