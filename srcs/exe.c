/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmashiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:12:12 by lmashiya          #+#    #+#             */
/*   Updated: 2017/09/07 21:02:26 by lmashiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	exe(char **args, char **envp)
{
	pid_t		pid;
	char		*dir;
	int			i;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		dir = ft_path_finder(envp, args);
		if (dir == NULL)
			exit(0);
		i = execve(dir, args, envp);
		if (i != 0)
			ft_putstr("ERROR");
		free(dir);
	}
	else if (pid < 0)
		ft_putstr("PID IS LESS THE ZERO!!!!!!!");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
}
