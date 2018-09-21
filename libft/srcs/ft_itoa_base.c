/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:10:01 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/23 10:07:06 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	long long		num;
	static char		*rep;
	static char		buff[65];
	char			*str;

	rep = "0123456789ABCDEF";
	str = &buff[64];
	*str = '\0';
	num = value;
	if (base < 2 || base > 16)
		return (0);
	if (num < 0)
		num *= -1;
	if (num == 0)
		*--str = rep[num % base];
	while (num != 0)
	{
		*--str = rep[num % base];
		num /= base;
	}
	if (value < 0 && base == 10)
		*--str = '-';
	return (str);
}
