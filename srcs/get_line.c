/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmashiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:16:49 by lmashiya          #+#    #+#             */
/*   Updated: 2017/09/07 21:06:09 by lmashiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char		get_char(void)
{
	char	chr;

	read(0, &chr, 1);
	return (chr);
}

static char		*resize_str(char *str, int size)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(size);
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	free(str);
	return (arr);
}

char			*ft_get_line(void)
{
	char	*line;
	char	c;
	int		i;
	int		size;

	size = 1024;
	line = (char *)malloc(size);
	i = 0;
	while (1)
	{
		c = get_char();
		if (c == '\n' || c == '\0')
		{
			line[i] = '\0';
			return (line);
		}
		if (size - 1 <= i)
		{
			size = size * 2;
			line = resize_str(line, size);
		}
		line[i++] = c;
	}
	line[i] = '\0';
	return (line);
}
