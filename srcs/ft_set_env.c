/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmashiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:16:01 by lmashiya          #+#    #+#             */
/*   Updated: 2017/09/07 21:05:41 by lmashiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_execute_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_execute_pwd(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 4;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			while (env[i][j])
			{
				ft_putchar(env[i][j]);
				j++;
			}
			ft_putchar('\n');
			return ;
		}
		i++;
	}
}

char	*ft_realloc(char *str, char *str2)
{
	char	*nstr;

	str = NULL;
	if (str2 == NULL)
		return (str);
	nstr = (char *)malloc(sizeof(char) * ft_strlen(str2));
	ft_strcpy(nstr, str2);
	return (nstr);
}

int		ft_findpoint(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

void	ft_setenv(char *arg, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(arg, env[i], ft_findpoint(arg, '=')) == 0)
		{
			env[i] = ft_realloc(env[i], arg);
			return ;
		}
		i++;
	}
	while (env[i] != NULL)
		i++;
	env[i] = ft_realloc(env[i], arg);
}
