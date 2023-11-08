/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:56:26 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/07 15:01:10 by anttorre         ###   ########.fr       */
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

int	prompt(char **line, t_data *d)
{
	char	cur_dir[500];
	char	**dir;

	dir = ft_split(getcwd(cur_dir, sizeof(cur_dir)), '/');
	if (!dir)
		return (free_dir(dir), EXIT_FAILURE);
	while (dir[d->i])
		d->i++;
	d->tmp = ft_strjoin(YELLOW_T, dir[d->i - 1]);
	free_dir(dir);
	d->tmp1 = ft_strjoin(BLUE_T, "minishell@");
	d->shell = ft_strjoin(d->tmp1, d->tmp);
	if (!d->tmp || !d->tmp1 || !d->shell)
		return (free(d->tmp), free(d->tmp1), free(d->shell), 1);
	free(d->tmp1);
	free(d->tmp);
	d->tmp = ft_strjoin(d->shell, RESET_COLOR "\x1b[1;31m ▸ \x1b[0m");
	if (!d->tmp)
		return (free(d->shell), EXIT_FAILURE);
	free(d->shell);
	*line = readline(d->tmp);
	free(d->tmp);
	if (!*line)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
