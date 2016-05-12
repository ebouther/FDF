/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:01:03 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 15:49:53 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertice	ft_vert_x_matrix(t_vertice v, t_matrix m)
{
	t_vertice	res;
	double		w;

	res.x = v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + m.m30;
	res.y = v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + m.m31;
	res.z = v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + m.m32;
	w = -v.z;
	if (w != 1)
	{
		res.x /= w;
		res.y /= w;
		res.z /= w;
	}
	return (res);
}

t_matrix	ft_projection_matrix(t_env *e)
{
	t_matrix	m;
	double		scale;

	scale = (1 / tan((e->cam.fov * 0.5) * (M_PI / 180)));
	ft_bzero_matrix(&m);
	m.m00 = scale;
	m.m11 = scale;
	m.m22 = -(e->cam.far) / (e->cam.far - e->cam.near);
	m.m32 = (-(e->cam.far) * e->cam.near) / (e->cam.far - e->cam.near);
	m.m23 = -1;
	m.m23 = 0;
	return (m);
}

void		ft_bzero_matrix(t_matrix *m)
{
	m->m00 = 0;
	m->m01 = 0;
	m->m02 = 0;
	m->m03 = 0;
	m->m10 = 0;
	m->m11 = 0;
	m->m12 = 0;
	m->m13 = 0;
	m->m20 = 0;
	m->m21 = 0;
	m->m22 = 0;
	m->m23 = 0;
	m->m30 = 0;
	m->m31 = 0;
	m->m32 = 0;
	m->m33 = 0;
}
