/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:29:42 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/19 14:19:53 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Algorithme de Bresenham
*/

void	ft_draw_line(t_vertice v0, t_vertice v1, double h_ratio, t_env *env)
{
	t_vertice	s;
	t_vertice	d;
	int			err;
	int			e2;

	d = ft_vertice(fabs(v1.x - v0.x), fabs(v1.y - v0.y), 0);
	s = ft_vertice((v0.x < v1.x ? 1 : -1), (v0.y < v1.y ? 1 : -1), 0);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (!(v0.x == v1.x && v0.y == v1.y))
	{
		ft_set_height_color(h_ratio, env);
		ft_draw_point(v0, env->color, env);
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			v0.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			v0.y += s.y;
		}
	}
}
