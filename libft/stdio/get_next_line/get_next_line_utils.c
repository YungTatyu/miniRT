/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:39:23 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/07 20:39:23 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (i < dstsize - dst_len - 1)
	{
		if (src[i] == '\0')
			break ;
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	char	*tmp1;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp1 = (char *)s1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ans = (char *)malloc(sizeof(char) * len);
	if (!ans)
	{
		free(tmp1);
		tmp1 = NULL;
		return (NULL);
	}
	*ans = '\0';
	ft_strlcat(ans, s1, ft_strlen(s1) + 1);
	ft_strlcat(ans, s2, len);
	free(tmp1);
	tmp1 = NULL;
	return (ans);
}
