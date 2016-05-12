#include "fdf.h"

static int	ft_hook_key_3(int keycode, t_env *e)
{
	if (keycode == I_KEY)
		ft_hook_up_down(0, e);
	else if (keycode == K_KEY)
		ft_hook_up_down(1, e);
	else if (keycode == L_KEY)
		ft_hook_left_right(0, e);
	else if (keycode == J_KEY)
		ft_hook_left_right(1, e);
	else if (keycode == PAV_PLUS)
		ft_hook_minus_plus(1, e);
	else if (keycode == PAV_MINUS)
		ft_hook_minus_plus(0, e);
	return (0);
}

static int	ft_hook_key_2(int keycode, t_env *e)
{
	if (keycode == ONE)
		ft_hook_pav_scale(11, e);
	else if (keycode == TWO)
		ft_hook_pav_scale(10, e);
	else if (keycode == RIGHT_ARROW)
		ft_hook_pav_scale(7, e);
	else if (keycode == LEFT_ARROW)
		ft_hook_pav_scale(6, e);
	else if (keycode == DOWN_ARROW)
		ft_hook_pav_scale(8, e);
	else if (keycode == UP_ARROW)
		ft_hook_pav_scale(9, e);
	else if (keycode == Q_KEY)
		ft_hook_pav_scale(0, e);
	else if (keycode == D_KEY)
		ft_hook_pav_scale(1, e);
	else if (keycode == Z_KEY)
		ft_hook_pav_scale(3, e);
	else if (keycode == S_KEY)
		ft_hook_pav_scale(2, e);
	else
		ft_hook_key_3(keycode, e);
	return (0);
}

int		ft_hook_key(int keycode, t_env *e)
{
	ft_putstr("KEYCODE :");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == ESC)
	{
		ft_free_vertices(e->map.v, e->map.w, e->map.h);
		exit(0);
	}
	else if (keycode == R_KEY)
		ft_hook_pav_scale(5, e);
	else if (keycode == F_KEY)
		ft_hook_pav_scale(4, e);
	else
		ft_hook_key_2(keycode, e);
	return (0);
}
