/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:41:16 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/05 20:22:35 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_exit(void)
{
	ft_putendl("error");
	exit(-1);
}

void	ft_bad_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
			ft_error_exit();
		i++;
	}
}

void	ft_read_error(char **split)
{
	static int	last_len = -1;
	int		len;

	len = 0;
	while (*split++)
		len++;
	if (last_len != -1 &&
		len != last_len)
		ft_error_exit();
	last_len = len;
}
