/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:13:31 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 13:30:27 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ctype.h"

int	ft_isint(char *s)
{
	size_t	i;
	long	num;

	i = 0;
	num = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	num = ft_strtol(s);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
