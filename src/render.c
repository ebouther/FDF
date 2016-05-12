/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:38:52 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/19 13:57:10 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_point(t_vertice point, int color, t_env *e)
{
	int i;
	
	if (point.x > WIN_WIDTH || point.x < 0 || point.y > WIN_HEIGHT || point.y < 0)
		return ;
	i = ((int)point.x * 4) + ((int)point.y * e->image.sizeline);
	e->image.data_addr[i] = color;
	e->image.data_addr[++i] = color >> 8;
	e->image.data_addr[++i] = color >> 16;
}

void	ft_draw_reload(t_env *e)
{
	e->image.img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->image.data_addr = mlx_get_data_addr(e->image.img, &(e->image.bpp),
		&(e->image.sizeline), &(e->image.endian));
	ft_proj_vertices(e->map.v, e->map.w, e->map.h, e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
	mlx_destroy_image(e->mlx, e->image.img);
}

int			ft_rgb(t_vertice rgb_min, t_vertice rgb_max, double y, double max_h)
{
	t_vertice	color;
	int			res;

	color.x = (y / max_h) * (fabs(rgb_min.x - rgb_max.x));
	color.y = (y / max_h) * (fabs(rgb_min.y - rgb_max.y));
	color.z = (y / max_h) * (fabs(rgb_min.z - rgb_max.z));
	res = (((int)(color.x + rgb_max.x) << 16) +
			((int)(color.y + rgb_max.y) << 8) + ((color.z + rgb_max.z)));
	return (res);
}

static void	ft_link_vertices(t_vertice ***proj, t_vertice ***v, t_env *e)
{
	int			i;
	int			j;

	i = 0;
	while (i < e->map.h)
	{
		j = 0;
		while (j < e->map.w)
		{
			if (j > 0)
				ft_draw_line(*(proj[i][j - 1]), *(proj[i][j]), /*fabs(v[i][j].y
					- v[i][j - 1].y) / fabs(proj[i][j].y - proj[i][j - 1].y)*/
					(v[i][j - 1]->y > v[i][j]->y ? v[i][j - 1]->y : v[i][j]->y), e);
			if (i > 0)
				ft_draw_line(*(proj[i - 1][j]), *(proj[i][j]), /*fabs(v[i][j].y
					- v[i][j - 1].y) / fabs(proj[i][j].y - proj[i][j - 1].y)*/ 
				(v[i - 1][j]->y > v[i][j]->y ? v[i - 1][j]->y : v[i][j]->y), e);
			j++;
		}
		i++;
	}
}

void		ft_proj_vertices(t_vertice ***v, int width, int height, t_env *e)
{
	int			i;
	int			j;
	t_vertice	***proj;
	t_vertice	transformation;

	proj = (t_vertice ***)malloc(sizeof(t_vertice **) * height);
	i = 0;
	while (i < height)
	{
		proj[i] = (t_vertice **)malloc(sizeof(t_vertice *) * width);
		j = 0;
		while (j < width)
		{
			proj[i][j] = (t_vertice *)malloc(sizeof(t_vertice));
			transformation = *(v[i][j]);
			transformation.x *= e->map.size.x;
			transformation.y *= e->map.size.y;
			transformation.z *= e->map.size.z;
			transformation = ft_rotate(transformation, e->map.center, ft_vertice(e->map.rot.x, e->map.rot.y, e->map.rot.z));
			transformation.x += e->map.translate.x;
			transformation.y += e->map.translate.y;
			transformation.z += e->map.translate.z;
			*(proj[i][j]) = ft_simple_perspective(transformation, e);
			ft_set_height_color(v[i][j]->y, e);
			ft_draw_point(*(proj[i][j]), e->color, e);
			j++;
		}
		i++;
	}
	e->map.center = ft_vertice(fabs(v[i - 1][j - 1]->x - v[0][0]->x), 0, -fabs(v[i - 1][j - 1]->z - v[0][0]->z));
	if (e->link == 1)
		ft_link_vertices(proj, v, e);
	ft_free_vertices(proj, width, height);
}
