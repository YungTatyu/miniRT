/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:07:00 by ryhara            #+#    #+#             */
/*   Updated: 2023/09/29 13:21:15 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdlib.h"

static double	check_atoi(const char *s, int *i, double *sign)
{
	double	num;

	num = 0;
	while ((s[*i] >= 9 && s[*i] <= 13) || s[*i] == 32)
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[(*i)++] == '-')
			*sign = -1;
	}
	while (s[*i] >= '0' && s[*i] <= '9')
		num = num * 10 + (s[(*i)++] - '0');
	return (num);
}

double	ft_atof(const char *s)
{
	double	sign;
	double	num;
	double	sm_num;
	int		count;
	int		i;

	sm_num = 0;
	sign = 1;
	i = 0;
	count = 0;
	num = check_atoi(s, &i, &sign);
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			sm_num = sm_num * 10 + (s[i++] - '0');
			count++;
		}
		while (count--)
			sm_num /= 10;
	}
	return ((num + sm_num) * sign);
}
