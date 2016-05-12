/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:59:42 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/19 14:27:00 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line_2d(t_vertice a, t_vertice b, t_env *env)
{
	double		coef_dir;
	t_vertice	d;
	double		x;
	double		y;
	double		e;

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	coef_dir = d.y / d.x;
	x = a.x;
	y = a.y;
	e = 0;
	while (x < b.x)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, env->color);
		if ((e = e + coef_dir) >= 0.5)
		{
			y = y + 1;
			e = e - 1;
		}
		x++;
	}
}

static void	ft_fill_bot_flat_triangle(t_vertice v1, t_vertice v2,
		t_vertice v3, t_env *e)
{
	double		coef_dir1;
	double		coef_dir2;
	t_vertice	a;
	t_vertice	b;

	a = ft_vertice(v1.x, v1.y, 0);
	b = ft_vertice(v1.x, v1.y, 0);
	coef_dir1 = (v2.x - v1.x) / (v2.y - v1.y);
	coef_dir2 = (v3.x - v1.x) / (v3.y - v1.y);
	while (a.y <= v2.y)
	{
		b.y = a.y;
		ft_draw_line_2d(a, b, e);
		a.x += coef_dir1;
		b.x += coef_dir2;
		a.y++;
	}
}

static void	ft_fill_top_flat_triangle(t_vertice v1, t_vertice v2,
		t_vertice v3, t_env *e)
{
	double		coef_dir1;
	double		coef_dir2;
	t_vertice	a;
	t_vertice	b;

	a = ft_vertice(v3.x, v3.y, 0);
	b = ft_vertice(v3.x, v3.y, 0);
	coef_dir1 = (v3.x - v1.x) / (v3.y - v1.y);
	coef_dir2 = (v3.x - v2.x) / (v3.y - v2.y);
	while (a.y > v1.y)
	{
		b.y = a.y;
		ft_draw_line_2d(a, b, e);
		a.x -= coef_dir1;
		b.x -= coef_dir2;
		a.y--;
	}
}

/*
**				 v1
**	 v1 ___ v2   /\
**		\ /   v2----v3
**		v3
*/

void		ft_draw_triangle(t_vertice v1, t_vertice v2, t_vertice v3, t_env *e)
{
	t_vertice	v4;
	t_vertice	tmp;

	ft_sort_vertices(&v1, &v2, &v3);
	v4 = ft_vertice(0, v2.y, 0);
	v4.x = v1.x + ((v2.y - v1.y) / (v3.y - v1.y)) * (v3.x - v1.x);
	if (v2.y == v3.y)
		ft_fill_bot_flat_triangle(v1, v2, v3, e);
	else if (v1.y == v2.y)
		ft_fill_top_flat_triangle(v1, v2, v3, e);
	else
	{
		if (v2.x > v4.x)
		{
			tmp = v4;
			v4 = v2;
			v2 = tmp;
		}
		ft_fill_bot_flat_triangle(v1, v2, v4, e);
		ft_fill_top_flat_triangle(v2, v4, v3, e);
	}
}
