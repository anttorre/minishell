/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:41:32 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/23 16:30:16 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_pwd(void)
{
	char	actual_dir[500];

	getcwd(actual_dir, 500);
	printf("%s\n", actual_dir);
}

void	exec_echo(char **s)
{
	int	option;
	int	size;

	option = 0;
	size = 0;
	while (s[size])
		size++;
	if (size > 1)
	{
		size = 0;
		while (s[++size] && !ft_strncmp(s[size], "-n", 2))
			option = 1;
		while (s[size])
		{
			printf("%s", s[size]);
			if (s[size + 1] || s[size][0] == '\0')
				printf(" ");
			size++;
		}
	}
	if (option == 0)
		printf("\n");
}

void	exec_env(t_data *d)
{
	t_env	*head;

	head = d->envp;
	while (head)
	{
		printf("%s%s\n", head->key, head->value);
		head = head->next;
	}
}

void	exec_unset(t_data *d, char *key)
{
	t_env	*aux;
	t_env	*del;
	t_env	*prev;

	if (!key)
		return ;
	aux = d->envp;
	prev = NULL;
	while (aux)
	{
		if (!ft_strncmp(aux->key, key, ft_strlen(key)))
		{
			del = aux;
			if (prev)
				prev->next = aux->next;
			else
				d->envp = aux->next;
			free(del->key);
			free(del->value);
			free(del);
			break ;
		}
		prev = aux;
		aux = aux->next;
	}
}

void	exec_export(t_data *d)
{
	
}
