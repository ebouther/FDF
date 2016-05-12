/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:42:20 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 14:44:38 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_hook_pav_up_down(t_vertice *translate, int mode, t_env *e)
{
	if (mode == 0)
		translate->x += 10.0;
	else if (mode == 1)
		translate->x -= 10.0;
	e->map.translate = ft_vertice(translate->x, translate->y, translate->z);
	ft_draw_reload(e);
}*/

void	ft_hook_up_down(int mode, t_env *e)
{
	if (mode == 0)
		e->map.rot.x += 10.0;
	else if (mode == 1)
		e->map.rot.x -= 10.0;
	ft_draw_reload(e);
}

void	ft_hook_left_right(int mode, t_env *e)
{
	if (mode == 0)
		e->map.rot.y -= 10.0;
	if (mode == 1)
		e->map.rot.y += 10.0;
	ft_draw_reload(e);
}

void	ft_hook_pav_scale(int mode, t_env *e)
{
	if (mode == 0)
		e->map.size.x -= 0.25;
	else if (mode == 1)
		e->map.size.x += 0.25;	
	else if (mode == 2)
		e->map.size.y -= 0.25;
	else if (mode == 3)
		e->map.size.y += 0.25;
	else if (mode == 4)
		e->map.size.z -= 0.25;
	else if (mode == 5)
		e->map.size.z += 0.25;
	else if (mode == 6)
		e->map.translate.x += e->map.w / 4;
	else if (mode == 7)
		e->map.translate.x -= e->map.w / 4;
	else if (mode == 8)
		e->map.translate.y += e->map.h / 4;
	else if (mode == 9)
		e->map.translate.y -= e->map.h / 4;
	else if (mode == 10)
		e->mode = 4;
	else if (mode == 11)
		e->mode = 1;
	ft_draw_reload(e);
}

void	ft_hook_minus_plus(int mode, t_env *e)
{
	if (mode == 0)
	{
		e->cam.fov -= 5;
		if (e->cam.fov <= 10)
			e->cam.fov = 10;
	}
	else if (mode == 1)
	{
		e->cam.fov += 5;
		if (e->cam.fov >= 170)
			e->cam.fov = 170;
	}
	ft_draw_reload(e);
}
