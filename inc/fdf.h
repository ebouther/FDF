/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:35:05 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/19 14:29:18 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"


# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

/*
** KEYCODES
*/
# define ESC 53
# define UP_ARROW 125
# define DOWN_ARROW 126
# define RIGHT_ARROW 123
# define LEFT_ARROW 124
# define PAV_PLUS 24
# define PAV_MINUS 27
# define PAGE_UP 34
# define PAGE_DOWN 32
# define SPACE 49
# define ONE 18
# define TWO 19
# define THREE 20 
# define FOUR 21
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define Z_KEY 13
# define Q_KEY 0
# define S_KEY 1
# define D_KEY 2
# define R_KEY 15
# define F_KEY 3

typedef struct	s_vertice
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vertice;

typedef struct	s_matrix
{
	double		m00;
	double		m01;
	double		m02;
	double		m03;
	double		m10;
	double		m11;
	double		m12;
	double		m13;
	double		m20;
	double		m21;
	double		m22;
	double		m23;
	double		m30;
	double		m31;
	double		m32;
	double		m33;
}				t_matrix;

typedef struct	s_camera
{
	double		fov;
	double		aspect_ratio;
	double		near;
	double		far;
	t_vertice	pos;
	t_matrix	w_to_c;
	t_matrix	proj_matrix;
}				t_camera;

typedef struct	s_img
{
	void		*img;
	int			width;
	int			height;
	char		*data_addr;
	int			bpp;
	int			sizeline;
	int			endian;
	int			color;
}				t_img;

typedef struct	s_map
{
	int			h;
	int			w;
	t_vertice	***v;
	t_vertice	rot;
	t_vertice	translate;
	t_vertice	size;
	t_vertice	center;
	double		max_h;
	double		min_h;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_camera	cam;
	t_img		image;
	t_map		map;
	int			color;
	int			link;
	int			mode;
}				t_env;

/*
** objects.c
*/
int				ft_draw_square(int square, t_env *env);
void			ft_draw_line(t_vertice v0, t_vertice v1,
		double h_ratio, t_env *env);

/*
** utils.c
*/
t_vertice		ft_vertice(double x, double y, double z);
void			ft_sort_vertices(t_vertice *v1, t_vertice *v2, t_vertice *v3);
void			ft_disp_vertices_pos(t_vertice **v, int width, int height);
void			ft_free_vertices(t_vertice ***v, int width, int height);

/*
** transformation.c
*/
t_vertice		ft_get_triangle_center(t_vertice v1,
					t_vertice v2, t_vertice v3);
t_vertice		ft_rotate_2d(t_vertice v, t_vertice center, double theta);
t_vertice		ft_perspective(t_vertice v, t_env *e);
t_vertice		ft_simple_perspective(t_vertice v, t_env *e);

/*
** read.c
*/
t_vertice		***ft_get_map(char *file, int *map_width,
					int *map_height, t_env *e);

/*
** error.c
*/
void			ft_error_exit();
void			ft_read_error(char **split);
void			ft_bad_map(char *str);

/*
** render.c
*/
void			ft_proj_vertices(t_vertice ***v, int width,
					int height, t_env *e);
int				ft_rgb(t_vertice rgb_min, t_vertice rgb_max,
					double y, double max_h);
void			ft_draw_point(t_vertice v, int color, t_env *e);
void			ft_draw_reload(t_env *e);

/*
** matrix.c
*/
t_vertice		ft_vert_x_matrix(t_vertice v, t_matrix m);

/*
** line.c
*/
void			ft_line(t_vertice p1, t_vertice p2, t_env *e);

/*
** line.c
*/
void			ft_hook_up_down(int mode, t_env *e);
void			ft_hook_left_right(int mode, t_env *e);
void			ft_hook_minus_plus(int mode, t_env *e);
void			ft_hook_pav_scale(int mode, t_env *e);

/*
** rotation.c
*/
t_vertice		ft_rotate(t_vertice v, t_vertice center, t_vertice rot);

/*
** fill_vertex.c
*/
void			ft_draw_triangle(t_vertice v1, t_vertice v2,
					t_vertice v3, t_env *e);
/*
** colors.c
*/
void			ft_set_height_color(double y, t_env *e);

/*
** hook_call.c
*/
int		ft_hook_key(int keycode, t_env *e);

#endif
