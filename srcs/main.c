/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmashiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:17:08 by lmashiya          #+#    #+#             */
/*   Updated: 2017/09/07 21:08:00 by lmashiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**ft_env_dup(void)
{
	extern char **environ;
	char		**env;
	int			i;
	int			j;

	i = 0;
	env = (char **)malloc(sizeof(char *) * 40);
	while (environ[i] != NULL)
	{
		j = 0;
		env[i] = (char *)malloc(sizeof(char) * ft_strlen(environ[i] + 2));
		while (environ[i][j])
		{
			env[i][j] = environ[i][j];
			j++;
		}
		env[i][j] = '\0';
		i++;
	}
	env[i] = NULL;
	return (env);
}

int		main(void)
{
	char	**environ;

	environ = ft_env_dup();
	execve("clear", (char **)"clear", environ);
	launch_s(environ);
	return (0);
}
