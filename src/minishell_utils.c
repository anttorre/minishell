/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:56:26 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/03 14:59:16 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_env_paths(char **env, t_data *d)
{
	while (env)
	{
		if (!ft_strncmp("PATH", *env, 4))
			break ;
		env++;
	}
	*env += 5;
	d->env = ft_split(*env, ':');
	if (!d->env)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	prompt(char *line, t_data *d)
{
	char	cur_dir[500];
	char	*tmp;
	char	*tmp1;
	char	*shell;
	char	**dir;

	dir = ft_split(getcwd(cur_dir, sizeof(cur_dir)), '/');
	if (!dir)
		return ;
	while (dir[d->i])
		d->i++;
	tmp = ft_strjoin(BLUE_T, dir[d->i - 1]);
	tmp1 = ft_strjoin(YELLOW_T, "minishell@");
	shell = ft_strjoin(tmp1, tmp);
	if (!tmp || !tmp1 || !shell)
		return ;
	free(tmp1);
	free(tmp);
	shell = ft_strjoin(shell, RESET_COLOR " > ");
	if (!shell)
		return ;
	line = readline(shell);
}
