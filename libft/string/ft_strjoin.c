/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:38:10 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 12:49:15 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ans = (char *)malloc(sizeof(char) * len);
	if (!ans)
		return (NULL);
	*ans = '\0';
	ft_strlcat(ans, s1, ft_strlen(s1) + 1);
	ft_strlcat(ans, s2, len);
	return (ans);
}
