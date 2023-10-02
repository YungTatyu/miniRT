
#ifndef VECTOR3D_H
# define VECTOR3D_H

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}t_vector3d;

t_vector3d	vector3d_add(t_vector3d p1, t_vector3d p2);
t_vector3d	vector3d_sub(t_vector3d p1, t_vector3d p2);
t_vector3d	vector3d_mul(t_vector3d p1, t_vector3d p2);
t_vector3d	vector3d_div(t_vector3d p1, t_vector3d p2);

#endif
