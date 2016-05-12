/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:35:15 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/05 20:18:50 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init_env(t_env *e)
{
	e->cam.fov = 90;
	e->cam.aspect_ratio = WIN_WIDTH / WIN_HEIGHT;
	e->cam.near = 0.1;
	e->cam.far = 100;
	e->color = 0xFF0000;
	e->map.rot = ft_vertice(0, 0, 0);
	e->map.max_h = 0;
	e->map.min_h = 0;
	e->cam.w_to_c.m31 = -10;
	e->cam.w_to_c.m32 = -20;
	e->link = 1;
	e->map.translate = ft_vertice(-20, 10, 0);
	e->map.size = ft_vertice(1, 1, 1);
	e->mode = 1;
}

static int		ft_expose_hook(t_env *e)
{
	ft_draw_reload(e);
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		env;
	int			width;
	int			height;

	if (argc != 2)
		ft_error_exit();
	ft_init_env(&env);
	env.map.v = ft_get_map(argv[1], &width, &height, &env);
	env.map.h = height;
	env.map.w = width;
	env.map.center = ft_vertice(fabs(env.map.w / 2.0), -5, -fabs(env.map.h / 2.0) - 10);
	if (!(env.mlx = mlx_init()))
		return (-1);
	if (!(env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		return (-1);
	mlx_key_hook(env.win, ft_hook_key, &env);
	mlx_expose_hook(env.win, ft_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
