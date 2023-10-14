/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_radiance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:54:18 by tterao            #+#    #+#             */
/*   Updated: 2023/10/14 17:02:35 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "objs.h"
#define DIFFUSE_REFLECTION 0.69f /* 拡散反射係数 */
#define AMBIENT_LIGHT_REFLECTION 1.0 /* 環境光反射係数 */
#define SPECULAR_REFLECTION 0.5f /* 鏡面反射係数 */
#define GLOSSINESS 100.0 /* 光沢度 */
#define COLOR 255.0 /* colorの範囲 */

t_vector3d	get_intersection_pos(const t_vector3d camera_pos,
				const double t, const t_vector3d ray);
t_vector3d	get_incidence_vector(const t_vector3d light_pos,
				const t_vector3d intersection_pos);
t_vector3d	get_normal_vector(const t_vector3d intersection_pos,
				t_objs *node);
double		get_incidence_dot(t_global_data *data, const t_objs *node,
				const t_vector3d ray, const double t);
double		shadow_res(t_global_data *data, t_vector3d shadow_ray,
				t_vector3d intersection_pos);

static t_fcolor	_calc_radiance(
	t_color color, const t_color ambient_light_radiance,
		const double light_diffuse_radiance,
		const double light_specular_reflection_radiance)
{
	t_fcolor	radiance;

	radiance.red = (color.red * constrain((light_diffuse_radiance
					+ color_to_fcolor(ambient_light_radiance.red)
					+ light_specular_reflection_radiance), 0.0, 1.0));
	radiance.green
		= (color.green * constrain((light_diffuse_radiance
					+ color_to_fcolor(ambient_light_radiance.green)
					+ light_specular_reflection_radiance), 0.0, 1.0));
	radiance.blue
		= (color.blue * constrain((light_diffuse_radiance
					+ color_to_fcolor(ambient_light_radiance.blue)
					+ light_specular_reflection_radiance), 0.0, 1.0));
	return (radiance);
}

/**
 * @brief 直接光の拡散反射光の放射輝度𝑅𝑑の内積を計算する
 *
 * @param ray
 * @param incidence_vec 入射ベクトル
 * @param normal 法線ベクトル
 * @return double
 */
static double	_calc_light_specular_reflection_radiance_dot(
				t_vector3d ray, t_vector3d incidence_vec, t_vector3d normal)
{
	const t_vector3d	regular_reflection = vector3d_sub(
			vector3d_fmulv(2.0 * vector3d_dot(normal, incidence_vec),
				normal),
			incidence_vec);
	const t_vector3d	rev_ray = vector3d_normalize(
			vector3d_fmulv(-1.0, ray));
	double				dot;

	dot = vector3d_dot(rev_ray, regular_reflection);
	return (constrain(dot, 0.0, 1.0));
}

/**
 * @brief 内積(𝐯⃗ ⋅𝐫⃗ )を計算する
 *
 * 視線ベクトルの逆ベクトル𝐯と正反射ベクトル𝐫の内積
 *
 * @param ray
 * @param dot
 * @param incidence_vec
 * @param normal_vec
 * @return double
 */
static double	_get_light_specular_reflection_dot(
			const t_vector3d ray, const double dot,
			const t_vector3d incidence_vec, const t_vector3d normal_vec)
{
	if (dot <= 0.0)
		return (0.0);
	return (
		_calc_light_specular_reflection_radiance_dot
		(ray, incidence_vec, normal_vec)
	);
}

/**
 * @brief 反射光の放射輝度𝑅𝑟を計算する
 *
 * 以下三つの足し算
 * 環境光
 * 拡散反射光
 * 鏡面反射光
 *
 * ambient_light_radiance:環境光の反射光の放射輝度
 * light_diffuse_radiance:直接光の拡散反射光の放射輝度
 * light_specular_reflection_radiance:直接光の鏡面反射光の放射輝度
 *
 * @param data
 * @param node
 * @param ray
 * @param t
 * @return double
 */
t_fcolor	get_radiance(t_global_data *data, t_objs *node,
							t_vector3d ray, const double t)
{
	const t_color	ambient_light_radiance = color_fmulc(
			data->ambient_light->ratio, data->ambient_light->color);
	const double	dot = get_incidence_dot(data, node, ray, t);
	const double	light_diffuse_radiance
		= data->light->ratio * dot;
	const double	light_specular_reflection_radiance
		= pow(_get_light_specular_reflection_dot(
				ray, dot, get_incidence_vector(data->light->coordinate,
					get_intersection_pos(data->camera->coordinate, t, ray)),
				get_normal_vector(get_intersection_pos(
						data->camera->coordinate, t, ray),
					node)
				), GLOSSINESS
			)
		* SPECULAR_REFLECTION * data->light->ratio;

	if (shadow_res(data, get_incidence_vector(data->light->coordinate,
				get_intersection_pos(data->camera->coordinate, t, ray)),
			get_intersection_pos(data->camera->coordinate, t, ray)) >= 0.0)
		return (_calc_radiance(objs_get_color(node),
				ambient_light_radiance, 0.0, 0.0));
	return (
		_calc_radiance(objs_get_color(node), ambient_light_radiance,
			light_diffuse_radiance, light_specular_reflection_radiance)
	);
}
