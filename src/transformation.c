/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:47:06 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 16:21:35 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertice	ft_get_triangle_center(t_vertice v1, t_vertice v2, t_vertice v3)
{
	t_vertice vect1;

	ft_sort_vertices(&v1, &v2, &v3);
	vect1 = ft_vertice((((v3.x + (v2.x - v1.x)) - v1.x) / 4) + v1.x,
			(((v3.y + (v2.y - v1.y)) - v1.y) / 4) + v1.y, 0);
	return (vect1);
}

/*
** ft_rotate_2d => angle in degrees
** Use ft_get_triangle_center(v1, v2, v3) to get center of triangle
*/

t_vertice	ft_rotate_2d(t_vertice v, t_vertice center, double theta)
{
	t_vertice r;
	t_vertice vt;

	theta *= (M_PI / 180);
	vt = ft_vertice(v.x - center.x, v.y - center.y, 0);
	r = ft_vertice((vt.x * cos(theta)) - (vt.y * sin(theta)),
			(vt.x * sin(theta)) + (vt.y * cos(theta)), 0);
	r = ft_vertice(r.x + center.x, r.y + center.y, 0);
	return (r);
}

/*t_vertice	ft_perspective(t_vertice v, t_env *e)
{
	t_vertice pScreen;
	t_vertice pRaster;
	t_vertice pNDC;

	pScreen.x = v.x / -v.z;
	pScreen.y = v.y / -v.z;
	// If the x- or y-coordinate absolute value is greater than the canvas width 
	// // or height respectively, the point is not visible
	//if (fabs(pScreen.x) > canvasWidth || fabs(pScreen.y) > canvasHeight)
	//	return false;
	// // Normalize. Coordinates will be in the range [0,1]
	pNDC.x = (pScreen.x + WIN_WIDTH / 2) / WIN_WIDTH;
	pNDC.y = (pScreen.y + WIN_HEIGHT / 2) / WIN_HEIGHT;
	// Finally convert to pixel coordinates. Don't forget to invert the y coordinate
	pRaster.x = (int)(pNDC.x * WIN_WIDTH);
	pRaster.y = (int)((1 - pNDC.y) * WIN_HEIGHT);
	return (pRaster); 
}*/

t_vertice	ft_simple_perspective(t_vertice v, t_env *e)
{
	t_vertice	proj;
	t_vertice	nor;
	t_vertice	ras;
	double		scale;

	scale = (1 / tan((e->cam.fov * 0.5) * (M_PI / 180)));
	proj.w = -v.z;
	proj.x = (v.x * scale) / proj.w;
	proj.y = v.y * scale / proj.w;
	proj.z = v.z * (-(e->cam.far) / (e->cam.far - e->cam.near));
	nor.x = (proj.x + 1) / 2;
	nor.y = (1 - proj.y) / 2;
	ras.x = (int)(nor.x * WIN_WIDTH);
	ras.y = (int)(nor.y * WIN_HEIGHT);
	if (ras.x == WIN_WIDTH)
		ras.x = WIN_WIDTH - 1;
	if (ras.y == WIN_HEIGHT)
		ras.y = WIN_HEIGHT - 1;
	return (ras);
}
