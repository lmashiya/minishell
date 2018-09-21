/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmashiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:04:27 by lmashiya          #+#    #+#             */
/*   Updated: 2017/09/07 21:25:27 by lmashiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static int	o_args(char **args, int b, char **envp)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(args[0], "env") == 0 || ft_strcmp(args[0], "setenv")
			== 0 || ft_strcmp(args[0], "unsetenv") == 0)
		env_mod(args, envp);
	else if (ft_strcmp(args[0], "cd") == 0)
		b = ft_cd(args, envp);
	else if (ft_even_odd(args, '\'') == 1 || ft_even_odd(args, '"') == 1)
		args = ft_inhibitors_quo(args);
	else
		b = 2;
	return (b);
}

void		launch_s(char **envp)
{
	char	*line;
	char	**args;
	int		b;

	b = 1;
	ft_putstr("\t\t\t\tCODEBAKER BAKED V1.0 \n\n\n");
	while (b != 0)
	{
		ft_putstr("BUNS$> ");
		line = ft_epur_str(ft_get_line());
		args = (char**)malloc(sizeof(args) * 20);
		args = ft_strsplit(line, ' ');
		free(line);
		if (ft_strlen(line) > 0 && args[0] != NULL)
		{
			if (ft_strcmp(args[0], "exit") == 0)
				b = 0;
			else
				b = o_args(args, b, envp);
			if (b == 2)
				exe(args, envp);
		}
		ft_2d_free(args);
	}
}
