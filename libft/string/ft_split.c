/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:42:10 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 12:48:54 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

static size_t	word_count(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break ;
		while (*str && *str != c)
			str++;
		count++;
	}
	return (count);
}

static void	free_all(char **array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**do_split(char **array, char *str, char c, size_t arr_len)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*str && arr_len--)
	{
		while (*str == c)
			str++;
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		array[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!array[j])
		{
			free_all(array, j);
			return (NULL);
		}
		ft_strlcpy(array[j++], str, (i + 1));
		str += i;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*str;
	size_t	arr_len;

	str = (char *)s;
	arr_len = word_count(str, c);
	array = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!array)
		return (NULL);
	if (!do_split(array, str, c, arr_len))
		return (NULL);
	return (array);
}
