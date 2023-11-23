/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:22 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/23 15:32:57 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# define WHITE_T "\x1b[1;37m"
# define YELLOW_T "\x1b[1;33m"
# define RESET_COLOR "\x1b[0m"
# define BLUE_T "\x1b[1;36m"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}			t_env;

typedef struct s_data
{
	char	**env;
	char	***cmds;
	char	*tmp;
	char	*line;
	char	*tmp1;
	char	*shell;
	int		i;
	int		f_pipe;
	int		f_redir;
	int		f_append;
	int		c_append;
	int		c_redir;
	int		c_pipe;
	t_env	*envp;
	t_env	*aux;
}			t_data;

void		free_all(t_data *d);
void		free_dir(char **dir);
int			get_env_paths(char **env, t_data *d);
int			prompt(char **line, t_data *d);
void		init_struct(t_data *d);
char		**split_loop(char *s, char d, t_data *data);
char		**ft_split_quotes(char *str, char d, t_data *data);
void		free_split_quotes(char **arr);
void		process_input(char *input, t_data *d, char **envp);
void		count_lex(t_data *d, char *s);
int			get_paths(t_data *d);
void		msg_err(char *str);
void		exec_cmd(char *path, char **cmd, char **env);
void		exec_pwd(void);
void		exec_echo(char **s);
void		start_env(t_data *d, char **env);
void		exec_env(t_data *d);
void		exec_unset(t_data *d, char *key);

#endif