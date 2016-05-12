/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:52:28 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/24 19:56:15 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	digit_to_char(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	else
		return ('A' - 10 + digit);
}

char		*ft_itoa_base(int value, int base)
{
	int		negative;
	char	*str;
	int		length;
	int		value2;

	if (value == -2147483648)
		return ("-2147483648");
	negative = value < 0 && base == 10;
	value = value < 0 ? value * -1 : value;
	length = 1;
	value2 = value;
	while (value2 >= base)
	{
		value2 /= base;
		length++;
	}
	str = (char*)malloc(sizeof(char) * ((length += negative) + 1));
	str[0] = '-';
	str[length] = '\0';
	while (length-- > negative)
	{
		str[length] = digit_to_char(value % base);
		value /= base;
	}
	return (str);
}
