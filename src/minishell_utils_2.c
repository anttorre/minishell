/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:31 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/17 16:42:35 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msg_err(char *str)
{
	perror(str);
}

void	exec_cmd(char *path, char **cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (execve(path, cmd, env) == -1)
			msg_err("bash");
	}
	else
		waitpid(pid, &status, 0);
}
