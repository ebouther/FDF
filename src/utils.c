/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:50:21 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 15:54:32 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_free_vertices(t_vertice ***v, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_memdel((void **)&(v[i][j]));
			j++;
		}
		ft_memdel((void **)&(v[i]));
		i++;
	}
	ft_memdel((void **)&(v));
}

void			ft_disp_vertices_pos(t_vertice **v, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putstr(ft_strdup("\n====>"));
			ft_putstr(ft_strdup("\nX : "));
			ft_putnbr(v[i][j].x);
			ft_putstr(ft_strdup("\nY : "));
			ft_putnbr(v[i][j].y);
			ft_putstr(ft_strdup("\nZ : "));
			ft_putnbr(v[i][j].z);
			j++;
		}
		ft_putstr(ft_strdup("\n\n===================================="));
		i++;
	}
}

t_vertice		ft_vertice(double x, double y, double z)
{
	t_vertice v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

static void		ft_sort_by_x(t_vertice *v1, t_vertice *v2, t_vertice *v3)
{
	t_vertice tmp;

	if (v3->x == v2->x && v3->x < v2->x)
	{
		tmp = *v3;
		*v3 = *v2;
		*v2 = tmp;
	}
	if (v1->x == v2->x && v1->x > v2->x)
	{
		tmp = *v1;
		*v1 = *v2;
		*v2 = tmp;
	}
}

void			ft_sort_vertices(t_vertice *v1, t_vertice *v2, t_vertice *v3)
{
	t_vertice tmp;

	if (v3->y < v2->y)
	{
		tmp = *v2;
		*v2 = *v3;
		*v3 = tmp;
	}
	if (v2->y < v1->y)
	{
		tmp = *v1;
		*v1 = *v2;
		*v2 = tmp;
	}
	if (v3->y < v2->y)
	{
		tmp = *v2;
		*v2 = *v3;
		*v3 = tmp;
	}
	ft_sort_by_x(v1, v2, v3);
}
