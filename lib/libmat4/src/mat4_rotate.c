/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:23:22 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/01/20 09:23:43 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	get_axis_x_rotation_matrix(t_mat4 *m, float theta)
{
	m->m[5] = cos(theta);
	m->m[6] = sin(theta);
	m->m[9] = -sin(theta);
	m->m[10] = cos(theta);
}

void	get_axis_y_rotation_matrix(t_mat4 *m, float theta)
{
	m->m[0] = cos(theta);
	m->m[2] = -sin(theta);
	m->m[8] = sin(theta);
	m->m[10] = cos(theta);
}

void	get_axis_z_rotation_matrix(t_mat4 *m, float theta)
{
	m->m[0] = cos(theta);
	m->m[1] = sin(theta);
	m->m[4] = -sin(theta);
	m->m[5] = cos(theta);
}

t_mat4	mat4_rotate_axis(t_mat4 m, int axis, float angle)
{
	t_mat4	r;
	float	theta;

	mat4_set(&r, IDENTITY);
	theta = angle * (M_PI / 180);
	if (axis == AXIS_X)
	{
		get_axis_x_rotation_matrix(&r, theta);
		m = mat4_mul(m, r);
	}
	else if (axis == AXIS_Y)
	{
		get_axis_y_rotation_matrix(&r, theta);
		m = mat4_mul(m, r);
	}
	else if (axis == AXIS_Z)
	{
		get_axis_z_rotation_matrix(&r, theta);
		m = mat4_mul(m, r);
	}
	return (m);
}
