/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:38:52 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/19 13:57:10 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_color_mode_4(double y, t_env *e)
{	
	int ratio;

	ratio = 10;
	if (-y < 0)
		e->color = ft_rgb(ft_vertice(10, 0, 125),
			ft_vertice(48, 116, 242), -y, -(double)(e->map.min_h));
	else if (-y >= 0)
	{
		e->color = ft_rgb(ft_vertice(153, 0, 153),
			ft_vertice(255, 255, 255), -y, (double)(e->map.max_h));
	}
}

static void	ft_color_mode_3(double y, t_env *e)
{	
	int ratio;

	ratio = 10;
	if (-y < 0)
		e->color = ft_rgb(ft_vertice(10, 0, 125),
			ft_vertice(48, 116, 242), -y, -(double)(e->map.min_h));
	else if (-y >= 0 && -y < ((e->map.max_h / 9)))
	{
		e->color = ft_rgb(ft_vertice(0, 255, 0),
			ft_vertice(0, 60, 0), -y, (double)(e->map.max_h / 3));
	}
	else if ((-y >= (e->map.max_h / 9))
		&& (-y < (e->map.max_h - (e->map.max_h / 6))))
		e->color = ft_rgb(ft_vertice(255, 255, 255), ft_vertice(60, 40, 0),
				-y, (double)(e->map.max_h - (e->map.max_h / 6)));
	else if (-y >= (e->map.max_h - (e->map.max_h / 6)))
		e->color = 0xFFFFFF;
}

static void	ft_color_mode_2(double y, t_env *e)
{	
	int ratio;

	ratio = 10;
	if (-y < 0)
		e->color = ft_rgb(ft_vertice(10, 0, 125),
			ft_vertice(48, 116, 242), -y, -(double)(e->map.min_h));
	else if (-y >= 0 && -y < ((e->map.max_h / 9)))
	{
		e->color = ft_rgb(ft_vertice(0, 255, 0),
			ft_vertice(0, 60, 0), -y, (double)(e->map.max_h / 3));
	}
	else if ((-y >= (e->map.max_h / 9))
		&& (-y < (e->map.max_h - (e->map.max_h / 6))))
		e->color = ft_rgb(ft_vertice(255, 255, 255), ft_vertice(60, 40, 0),
				-y, (double)(e->map.max_h - (e->map.max_h / 6)));
	else if (-y >= (e->map.max_h - (e->map.max_h / 6)))
		e->color = 0xFFFFFF;
}

static void	ft_color_mode_1(double y, t_env *e)
{	
	int ratio;

	ratio = 10;
	if (-y < 0)
		e->color = ft_rgb(ft_vertice(10, 0, 125),
			ft_vertice(48, 116, 242), -y, -(double)(e->map.min_h));
	else if (-y >= 0 && -y < ((e->map.max_h / 9)))
	{
		e->color = ft_rgb(ft_vertice(0, 255, 0),
			ft_vertice(0, 60, 0), -y, (double)(e->map.max_h / 3));
	}
	else if ((-y >= (e->map.max_h / 9))
		&& (-y < (e->map.max_h - (e->map.max_h / 6))))
		e->color = ft_rgb(ft_vertice(255, 255, 255), ft_vertice(60, 40, 0),
				-y, (double)(e->map.max_h - (e->map.max_h / 6)));
	else if (-y >= (e->map.max_h - (e->map.max_h / 6)))
		e->color = 0xFFFFFF;
}

void		ft_set_height_color(double y, t_env *e)
{
	if (e->mode == 1)
		ft_color_mode_1(y, e);
	else if (e->mode == 2)
		ft_color_mode_2(y, e);
	else if (e->mode == 3)
		ft_color_mode_3(y, e);
	else
		ft_color_mode_4(y, e);
}
