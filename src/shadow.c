
#include "miniRT.h"
#define C_EPSILON 512.0f

#include "stdio.h"
float	shadow_res(t_global_data *data, t_vector3d shadow_ray, t_vector3d intersection_pos)
{
	t_objs				*obj;
	const t_vector3d	shadow_ray_start = vector3d_add(intersection_pos,
			vector3d_fmulv((1.0f / C_EPSILON), shadow_ray));
	const float			t = hit_object(shadow_ray_start, data->objs_list, shadow_ray, &obj);
	const float	distance_to_light = vector3d_mag(vector3d_sub(data->light->coordinate, intersection_pos)) - (1.0f / C_EPSILON);

	if (t < distance_to_light)
		return (t);
	return (-1.0f);
}
