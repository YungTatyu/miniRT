/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:33:46 by tterao            #+#    #+#             */
/*   Updated: 2023/10/14 14:33:49 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include "vector3d.h"
#include <math.h>
#include <mlx.h>

/**
 * @brief 解の公式のtを求める、二つのtのうち，値が正でかつ小さい方を𝑡とする
 *
 * @param a
 * @param b
 * @param c
 * @return double
 */
static double	_calc_t(double a, double b, double c)
{
	const double	t1 = (-b + sqrt(pow(b, 2.0) - (4.0 * a * c))) / (2.0 * a);
	const double	t2 = (-b - sqrt(pow(b, 2.0) - (4.0 * a * c))) / (2.0 * a);

	if (t1 > 0.0 && t2 > 0.0)
		return (fmin(t1, t2));
	else
		return (fmax(t1, t2));
}

/**
 * @brief 球体とレイの交差判定をおこなう
 *
 * 解の公式に代入する
 *
 * @param ray
 * @param camera_pos
 * @param obj_pos
 * @param radius
 * @return double t レイのベクトル方程式：𝐩⃗ =𝐬⃗ +𝑡𝐝⃗
 */
double	hit_sphere(t_vector3d ray, t_vector3d camera_pos,
						t_vector3d obj_pos, double radius)
{
	const double	a = vector3d_mag_sq(ray);
	const double	b = 2.0 * vector3d_dot(
			vector3d_sub(camera_pos, obj_pos), ray);
	const double	c = vector3d_mag_sq(
			vector3d_sub(camera_pos, obj_pos)) - pow(radius, 2.0);
	const double	d = pow(b, 2.0) - (4.0 * a * c);

	if (d == 0.0)
		return (-(b) / (2.0 * a));
	else if (d < 0)
		return (-1.0);
	return (_calc_t(a, b, c));
}

/**
 * @brief 値nをmin~maxまでの範囲に制限する
 *
 * @param n
 * @param min
 * @param max
 * @return double
 */
double	constrain(double n, double min, double max)
{
	if (n > max)
		n = max;
	else if (n < min)
		n = min;
	return (n);
}
