/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:18:35 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 22:18:35 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdlib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (((size_t)SIZE_MAX / size) < nmemb)
		return (NULL);
	else
	{
		memory = (void *)malloc(nmemb * size);
		if (memory == NULL)
			return (NULL);
		ft_bzero(memory, (nmemb * size));
		return (memory);
	}
}
