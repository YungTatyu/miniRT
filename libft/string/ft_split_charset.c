/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:24:53 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 23:30:18 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

static size_t	word_count(char *str, char *charset)
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

static char	**do_split_charset(char **arr, char *str, char *set, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*str && len--)
	{
		while (*str && ft_strchr(set, *str))
			str++;
		i = 0;
		while (str[i] && !ft_strchr(set, str[i]))
			i++;
		arr[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!arr[j])
		{
			free_split_all(arr, j);
			return (NULL);
		}
		ft_strlcpy(arr[j], str, (i + 1));
		j++;
		str += i;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split_charset(char *str, char *charset)
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