/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:10:28 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 14:03:51 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ctype.h"

int	ft_isdouble(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (i != 0 && s[i] == '.')
	{
		i++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
	}
	if (s[i] != '\0')
		return (0);
	return (1);
}
