/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:32:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/23 15:39:07 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	process_input(char *input, t_data *d, char **env)
{
	(void) env;
	count_lex(d, input);
	char **c = ft_split(input, ' ');
	if (!ft_strncmp(c[0], "env", 3))
		exec_env(d);
	if (!ft_strncmp(c[0], "unset", 5))
		exec_unset(d, c[1]);
}

int	minishell(char **env, t_data *d)
{
	d->line = NULL;
	if (get_env_paths(env, d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	start_env(d, env);
	while (1)
	{
		if (prompt(&d->line, d) == EXIT_FAILURE)
			return (free(d->line), EXIT_FAILURE);
		add_history(d->line);
		process_input(d->line, d, env);
		free(d->line);
	}
	clear_history();
	if (d->line)
		free(d->line);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	(void) argv;
	(void) argc;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_struct(data);
	if (minishell(env, data) == EXIT_FAILURE)
		return (free_all(data), EXIT_FAILURE);
	return (free_all(data), EXIT_SUCCESS);
}
