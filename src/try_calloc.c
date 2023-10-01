/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:15:45 by tterao            #+#    #+#             */
/*   Updated: 2023/10/01 14:16:46 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*try_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
	{
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
