/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:24:19 by gmofoken          #+#    #+#             */
/*   Updated: 2017/09/07 21:02:09 by lmashiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	ft_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl(envp[i]);
		i++;
	}
}

int			env_mod(char **args, char **envp)
{
	if (ft_strcmp(args[0], "env") == 0)
		ft_env(envp);
	else if (ft_strcmp(args[0], "setenv") == 0 && ft_len(args) > 1)
	{
		ft_putendl("set_env-------");
		ft_setenv(args[1], envp);
	}
	else if (ft_strcmp(args[0], "unsetenv") == 0 && ft_len(args) > 1)
	{
		ft_putendl("unset_env--------");
		ft_unsetenv(envp, args[1]);
	}
	return (2);
}
