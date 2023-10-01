/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:24:53 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/30 17:10:48 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

static size_t	word_count(const char *str, char *charset)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str && !ft_strchr(charset, *str))
		{
			count++;
			while (*str && !ft_strchr(charset, *str))
				str++;
		}
	}
	return (count);
}

static void	free_split_all(char **array, size_t len)
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

static char	**do_split_charset(char **arr, const char *s, char *set, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*s && len--)
	{
		while (*s && ft_strchr(set, *s))
			s++;
		i = 0;
		while (s[i] && !ft_strchr(set, s[i]))
			i++;
		arr[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!arr[j])
		{
			free_split_all(arr, j);
			return (NULL);
		}
		ft_strlcpy(arr[j], s, (i + 1));
		j++;
		s += i;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split_charset(const char *str, char *charset)
{
	char	**array;
	size_t	arr_len;

	arr_len = word_count(str, charset);
	array = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!array)
		return (NULL);
	if (!do_split_charset(array, str, charset, arr_len))
		return (NULL);
	return (array);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*charset;
// 	char	**ans;
// 	int		i;
// 	int		count;

// 	str = "C 0,1,0     0,255,253   255      \n";
// 	charset = " ,\n";
// 	i = 0;
// 	count = (word_count(str, charset) + 1);
// 	printf("count : %d\n", count);
// 	ans = ft_split_charset(str, charset);
// 	if (ans == NULL)
// 		return (1);
// 	while (i < count)
// 	{
// 		printf("%d: %s\n", i, ans[i]);
// 		i++;
// 	}
// }