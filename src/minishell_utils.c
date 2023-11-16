/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:56:26 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/15 17:56:54 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_split_quotes(char *str, char d, t_data *data)
{
	char	**arr;

	arr = split_loop(str, d, data);
	if (!arr)
		return (free_split_quotes(arr), NULL);
	return (arr);
}

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
	return (d->i = 0, EXIT_SUCCESS);
}

void	count_lex(t_data *d, char *s)
{
	int		flag_quote;
	char	aux;
	char	aux2;

	aux = '\'';
	aux2 = '\"';
	while (*s)
	{
		while ((*s != aux && *s != aux2 && flag_quote) || (!flag_quote && *s))
		{
			while ((*s == '\'' || *s == '\"') && *s != '\0')
			{
				if (*s == '\'' || *s == '\"')
				{
					flag_quote = !flag_quote;
				}
				s++;
			}
			if (!flag_quote)
			{
				if (*s == '|')
				{
					d->f_pipe = 1;
					d->c_pipe++;
				}
				if (*s == ';')
				{
					d->f_dotcoma = 1;
					d->c_dotcoma++;
				}
				if (*s == '>')
				{
					d->f_redir = 1;
					d->c_redir++;
				}
				if (*s == '>' && *(s + 1) == '>')
				{
					d->f_append = 1;
					d->c_append++;
				}
			}
			s++;
		}
		s++;
	}
}

void	process_input(char *input, t_data *d)
{
	count_lex(d, input);
}
//b | c ；d 'pepe|;pepa' >