

#include "miniRT.h"

t_vector3d	vector3d_add(t_vector3d v1, t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector3d	vector3d_sub(t_vector3d v1, t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector3d	vector3d_mul(t_vector3d v1, t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

t_vector3d	vector3d_div(t_vector3d v1, t_vector3d v2)
{
	t_vector3d	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	return (result);
}
