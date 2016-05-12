/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:36:35 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 15:30:05 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static t_vertice	*ft_new_vertice(char *str, int rst, int *height, t_env *e)
{
	static double	x = 0;
	static double	z = -10;
	double		y;
	int				ratio;
	t_vertice		*ret;
	
	ft_bad_map(str);
	y = ft_atoi(str);
	ret = (t_vertice *)malloc(sizeof(*ret));
	ratio = 10;
	if (y / ratio > e->map.max_h)
		e->map.max_h = y / ratio;
	if (y / ratio < e->map.min_h)
		e->map.min_h = y / ratio;
	if (rst == 0)
	{
		x = 0;
		z -= 1;
	}
	x += 1;
	*ret = ft_vertice(x - (*height), -y / ratio, z);
	return (ret);
}

static t_vertice	**ft_fill_vertices(char **split, int *width,
		int *height, t_env *e)
{
	t_vertice		**res;
	static int		last_len = -1;
	int				len;
	int				i;

	len = -1;
	i = 0;
	while (split[++len] != '\0')
		;
	if (last_len != -1 && len != last_len)
		ft_error_exit();
	*width = len;
	res = (t_vertice **)malloc(sizeof(t_vertice*) * len);
	while (i < len)
	{
		res[i] = ft_new_vertice(split[i]/*(double)ft_atoi(split[i])*/, i, height, e);
		i++;
	}
	return (res);
}

static t_vertice	***ft_fill_map(char **split, int *width,
		int *height, t_env *e)
{
	int				h;
	int				i;
	t_vertice		***vertices;
	char			**spl;
	int				n;

	i = 0;
	h = -1;
	while (split[++h] != '\0')
		;
	*height = h;
	vertices = (t_vertice ***)malloc(sizeof(t_vertice **) * h);
	while (i < h)
	{
		n = 0;
		spl = ft_strsplit(split[i], ' ');
		ft_read_error(spl);
		vertices[i] = ft_fill_vertices(spl,
				width, height, e);
		while (spl[n])
			ft_memdel((void **)&spl[n++]);
		ft_memdel((void **)&spl);
		i++;
	}
	return (vertices);
}

static void			ft_read_file(int fd, char **map)
{
	int		ret;
	char	*read;
	char	*tmp;

	while ((ret = get_next_line(fd, &read)))
	{
		if (ret == -1)
			ft_error_exit();
		if (ft_strcmp(read, "") != 0)
		{
			tmp = *map;
			*map = ft_strjoin(*map, "\n");
			ft_memdel((void **)(&tmp));
		}
		tmp = *map;
		*map = ft_strjoin(*map, read);
		ft_memdel((void **)(&tmp));
		ft_memdel((void **)(&read));
	}
	tmp = *map;
	*map = ft_strjoin(*map, (char *)"\n");
	ft_memdel((void **)(&tmp));
}

t_vertice			***ft_get_map(char *file, int *map_width,
		int *map_height, t_env *e)
{
	int			fd;
	char		**split;
	char		*map;
	t_vertice	***res;
	int		i;

	i = 0;
	map = (char *)malloc(sizeof(char));
	*map = '\0';
	fd = open(file, O_RDONLY);
	ft_read_file(fd, &map);
	ft_putstr((char *)"MAP : ");
	ft_putendl(map);
	split = ft_strsplit(map, '\n');
	res = ft_fill_map(split, map_width, map_height, e);
	while (split[i])
		ft_memdel((void **)&split[i++]);
	ft_memdel((void **)&split);
	ft_memdel((void **)&map);
	close(fd);
	return (res);
}
