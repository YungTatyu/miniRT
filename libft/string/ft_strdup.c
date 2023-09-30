/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:11:13 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 09:11:13 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*head;

	if (s == NULL)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s)+ 1));
	if (cpy == NULL)
		return (NULL);
	head = cpy;
	while (*s)
	{
		*cpy = *s;
		cpy++;
		s++;
	}
	*cpy = '\0';
	return (head);
}
