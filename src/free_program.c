/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:32:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/06 12:47:22 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_data *d)
{
	char	**ini;

	if (d->env)
	{
		ini = d->env;
		while (*d->env)
			free(*d->env++);
		free(ini);
	}
	free(d);
}

void	free_dir(char **dir)
{
	int	i;

	i = -1;
	if (dir)
	{
		while (dir[++i])
			free(dir[i]);
		free(dir);
	}
}
