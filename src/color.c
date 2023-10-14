/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:32:00 by tterao            #+#    #+#             */
/*   Updated: 2023/10/14 16:55:31 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#define COLOR 255.0 /* colorの範囲 */

/**
 * @brief colorを色を追加する
 *
 * @param color
 * @param adding_num
 */
void	color_add(t_color color, double adding_num)
{
	color.red += adding_num;
	color.green += adding_num;
	color.blue += adding_num;
}

/**
 * @brief colorを実数で表された色に変換する
 *
 * @param color
 * @return double
 */
double	color_to_fcolor(double color)
{
	return (color / COLOR);
}

/**
 * @brief 実数で表された色をcolor(0~255)に変換する
 *
 * @param fcolor
 * @return double
 */
double	color_to_color(double fcolor)
{
	double	color;

	color = fcolor * COLOR;
	return (constrain(color, 0.0, COLOR));
}

t_color	color_fmulc(double f, const t_color c)
{
	t_color	result;

	result.red = f * c.red;
	result.green = f * c.green;
	result.blue = f * c.blue;
	return (result);
}
