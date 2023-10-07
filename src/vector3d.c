

#include "miniRT.h"
#include <stdio.h>

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

void	vector3d_print(t_vector3d v)
{
	printf("x=%f, y=%f, z=%f\n", v.x, v.y, v.z);
}
