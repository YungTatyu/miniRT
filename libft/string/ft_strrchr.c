/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:34:45 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 16:34:45 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;
	char	*ans;

	pos = (char *)s;
	ans = NULL;
	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return ((pos + ft_strlen(s)));
	while (*pos)
	{
		if (*pos == (char)c)
			ans = pos;
		pos++;
	}
	return (ans);
}
