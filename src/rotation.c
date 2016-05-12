/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:31:10 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 15:35:49 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertice	ft_rotate_x(t_vertice v, t_vertice center, t_vertice rot)
{
	t_vertice	vt;
	t_vertice	res;

	vt = v;
	vt = ft_vertice(v.x - center.x, v.y - center.y, v.z - center.z);
	res.x = v.x;
	res.y = (vt.y * cos(rot.x * (M_PI / 180)))
			+ (vt.z * sin(rot.x * (M_PI / 180)));
	res.z = (vt.y * -sin(rot.x * (M_PI / 180)))
			+ (vt.z * cos(rot.x * (M_PI / 180)));
	res = ft_vertice(res.x + center.x, res.y + center.y, res.z + center.z);
	return (res);
}

static t_vertice	ft_rotate_y(t_vertice v, t_vertice center, t_vertice rot)
{
	t_vertice	vt;
	t_vertice	res;

	vt = v;
	vt = ft_vertice(v.x - center.x, v.y - center.y, v.z - center.z);
	res.x = (vt.x * cos(rot.y * (M_PI / 180)))
			+ (vt.z * -sin(rot.y * (M_PI / 180)));
	res.y = v.y;
	res.z = (vt.x * sin(rot.y * (M_PI / 180)))
			+ (vt.z * cos(rot.y * (M_PI / 180)));
	res = ft_vertice(res.x + center.x, res.y + center.y, v.z + center.z);
	return (res);
}

static t_vertice	ft_rotate_z(t_vertice v, t_vertice center, t_vertice rot)
{
	t_vertice	vt;
	t_vertice	res;

	vt = v;
	vt = ft_vertice(v.x - center.x, v.y - center.y, v.z - center.z);
	res.x = (vt.x * cos(rot.z * (M_PI / 180)))
			+ (vt.y * sin(rot.z * (M_PI / 180)));
	res.y = (vt.x * -sin(rot.z * (M_PI / 180)))
			+ (vt.y * cos(rot.z * (M_PI / 180)));
	res.z = v.z;
	res = ft_vertice(res.x + center.x, res.y + center.y, v.z + center.z);
	return (res);
}

t_vertice			ft_rotate(t_vertice v, t_vertice center, t_vertice rot)
{
	t_vertice	res;

	res = ft_rotate_x(v, center, rot);
	res = ft_rotate_y(res, center, rot);
	res = ft_rotate_z(res, center, rot);
	return (res);
}
