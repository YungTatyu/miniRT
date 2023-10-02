

#include "miniRT.h"

t_vector3d	vector3d_add(t_vector3d p1, t_vector3d p2)
{
	t_vector3d	result;

	result.x = p1.x + p2.x;
	result.y = p1.y + p2.y;
	result.z = p1.z + p2.z;
	return (result);
}

t_vector3d	vector3d_sub(t_vector3d p1, t_vector3d p2)
{
	t_vector3d	result;

	result.x = p1.x - p2.x;
	result.y = p1.y - p2.y;
	result.z = p1.z - p2.z;
	return (result);
}

t_vector3d	vector3d_mul(t_vector3d p1, t_vector3d p2)
{
	t_vector3d	result;

	result.x = p1.x * p2.x;
	result.y = p1.y * p2.y;
	result.z = p1.z * p2.z;
	return (result);
}

t_vector3d	vector3d_div(t_vector3d p1, t_vector3d p2)
{
	t_vector3d	result;

	result.x = p1.x / p2.x;
	result.y = p1.y / p2.y;
	result.z = p1.z / p2.z;
	return (result);
}
