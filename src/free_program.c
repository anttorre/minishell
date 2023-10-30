/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:32:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/30 12:43:23 by anttorre         ###   ########.fr       */
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
