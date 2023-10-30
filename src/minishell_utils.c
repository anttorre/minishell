/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:56:26 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/30 12:31:36 by anttorre         ###   ########.fr       */
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
	return (EXIT_FAILURE);
}
