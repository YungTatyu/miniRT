/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_radiance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:54:18 by tterao            #+#    #+#             */
/*   Updated: 2023/10/10 15:19:53 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "objs.h"
#define DIFFUSE_REFLECTION 0.69f /* 拡散反射係数 */
#define AMBIENT_LIGHT_REFLECTION 1.0f /* 環境光反射係数 */
#define SPECULAR_REFLECTION 0.5f /* 鏡面反射係数 */
#define GLOSSINESS 100.0 /* 光沢度 */
#define COLOR 255.0f /* colorの範囲 */

t_vector3d	get_intersection_pos(const t_vector3d camera_pos,
				const float t, const t_vector3d ray);
t_vector3d	get_incidence_vector(const t_vector3d light_pos,
				const t_vector3d intersection_pos);
t_vector3d	get_normal_vector(const t_vector3d intersection_pos,
				t_objs *node);
float		get_incidence_dot(t_global_data *data, const t_objs *node,
				const t_vector3d ray, const float t);
float		shadow_res(t_global_data *data, t_vector3d shadow_ray,
				t_vector3d intersection_pos);

static t_fcolor	_calc_radiance(
	t_color color, const float ambient_light_radiance,
		const float light_diffuse_radiance,
		const float light_specular_reflection_radiance)
{
	t_fcolor	radiance;

	// radiance.red = (color_to_fcolor(color.red) * light_diffuse_radiance)
	// 	+ ambient_light_radiance + light_specular_reflection_radiance;
	// radiance.green
	// 	= (color_to_fcolor(color.green) * light_diffuse_radiance)
	// 	+ ambient_light_radiance + light_specular_reflection_radiance;
	// radiance.blue
	// 	= (color_to_fcolor(color.blue) * light_diffuse_radiance)
	// 	+ ambient_light_radiance + light_specular_reflection_radiance;
	radiance.red = (color.red * constrain((light_diffuse_radiance
		+ ambient_light_radiance + light_specular_reflection_radiance), 0.0f, 1.0f));
	radiance.green
		= (color.green * constrain((light_diffuse_radiance
		+ ambient_light_radiance + light_specular_reflection_radiance), 0.0f, 1.0f));
	radiance.blue
		= (color.blue * constrain((light_diffuse_radiance
		+ ambient_light_radiance + light_specular_reflection_radiance), 0.0f, 1.0f));
	// radiance.red = constrain(radiance.red, 0.0f, 1.0f) * COLOR;
	// radiance.green = constrain(radiance.green, 0.0f, 1.0f) * COLOR;
	// radiance.blue = constrain(radiance.blue, 0.0f, 1.0f) * COLOR;
	return (radiance);
}

/**
 * @brief 直接光の拡散反射光の放射輝度𝑅𝑑の内積を計算する
 *
 * @param ray
 * @param incidence_vec 入射ベクトル
 * @param normal 法線ベクトル
 * @return float
 */
static float	_calc_light_specular_reflection_radiance_dot
	(t_vector3d ray, t_vector3d incidence_vec, t_vector3d normal)
{
	const t_vector3d	regular_reflection = vector3d_sub(
			vector3d_fmulv(2.0f * vector3d_dot(normal, incidence_vec),
				normal),
			incidence_vec);
	const t_vector3d	rev_ray = vector3d_normalize(
			vector3d_fmulv(-1.0f, ray));
	float				dot;

	dot = vector3d_dot(rev_ray, regular_reflection);
	if (dot > 1.0f)
		dot = 1.0f;
	else if (dot < 0.0f)
		dot = 0.0f;
	return (dot);
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
 * @return float
 */
static float	_get_light_specular_reflection_dot(
			const t_vector3d ray, const float dot,
			const t_vector3d incidence_vec, const t_vector3d normal_vec)
{
	if (dot <= 0.0f)
		return (0.0f);
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
 * @return float
 */
t_fcolor	get_radiance(
		t_global_data *data, t_objs *node, t_vector3d ray, const float t)
{
	const float	ambient_light_radiance = AMBIENT_LIGHT_REFLECTION
		* data->ambient_light->ratio;
	const float	dot = get_incidence_dot(data, node, ray, t);
	const float	light_diffuse_radiance
		= data->light->ratio * dot;
	const float	light_specular_reflection_radiance
		= powf(_get_light_specular_reflection_dot(
				ray, dot,
				get_incidence_vector(data->light->coordinate,
					get_intersection_pos(data->camera->coordinate, t, ray)),
				get_normal_vector(get_intersection_pos(
						data->camera->coordinate, t, ray),
					node)
				), GLOSSINESS
			)
		* SPECULAR_REFLECTION * data->light->ratio;

	if (shadow_res(data, get_incidence_vector(data->light->coordinate,
				get_intersection_pos(data->camera->coordinate, t, ray)),
			get_intersection_pos(data->camera->coordinate, t, ray)) >= 0.0f)
		return (_calc_radiance(objs_get_color(node), ambient_light_radiance, 0.0f, 0.0f));
	return (
		_calc_radiance(objs_get_color(node), ambient_light_radiance,
			light_diffuse_radiance, light_specular_reflection_radiance)
	);
}
