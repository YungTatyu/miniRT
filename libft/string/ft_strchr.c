/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:34:39 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 16:34:39 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ans;

	ans = (char *)s;
	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return ((ans + ft_strlen(s)));
	while (*ans)
	{
		if (*ans == (char)c)
			return (ans);
		ans++;
	}
	return (NULL);
}
