/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:27:00 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/23 17:02:29 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap_i(char const *s, int (*f)(int))
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
