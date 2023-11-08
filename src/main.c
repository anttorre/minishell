/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:32:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/07 15:52:43 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	minishell(char **env, t_data *d);

static int	minishell(char **env, t_data *d)
{
	char	*line;

	line = NULL;
	if (get_env_paths(env, d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (1)
	{
		if (prompt(&line, d) == EXIT_FAILURE)
			return (free(line), EXIT_FAILURE);
		add_history(line);
		free(line);
	}
	clear_history();
	if (line)
		free(line);
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
