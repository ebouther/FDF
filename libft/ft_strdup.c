/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:06:36 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/23 14:28:38 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*cpy;
	unsigned int	j;

	j = 0;
	len = ft_strlen(s);
	if (!(cpy = (char *)malloc(sizeof(*cpy) * (len + 1))))
		return (NULL);
	while (j < len)
	{
		cpy[j] = s[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
