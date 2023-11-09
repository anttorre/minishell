/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:22 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/09 12:31:11 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# define WHITE_T   "\x1b[1;37m"
# define YELLOW_T "\x1b[1;33m"
# define RESET_COLOR    "\x1b[0m"
# define BLUE_T "\x1b[1;36m"

typedef struct s_data
{
	char	**env;
	char	**cmds;
	char	*tmp;
	char	*tmp1;
	char	*shell;
	int		i;
}	t_data;

void	free_all(t_data *d);
void	free_dir(char **dir);
int		get_env_paths(char **env, t_data *d);
int		prompt(char **line, t_data *d);
void	init_struct(t_data *d);
char	**split_loop(char *s, char d);
char	**ft_split_quotes(char *str, char d);
void	free_split_quotes(char **arr);
void	process_input(char *input, t_data *d);

#endif