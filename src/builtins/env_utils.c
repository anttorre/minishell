/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:54 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/28 11:34:33 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tmp(char **tmp)
{
	int	i;

	i = -1;
	if (tmp)
	{
		while (tmp[++i])
			free(tmp[i]);
		free(tmp);
	}
}

int	lstsize_env(t_env *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	lst_addenv_back(t_env **lst, t_env *new, char **tmp)
{
	t_env	*first_node;

	if (new == NULL)
		return ;
	new->key = ft_strdup(tmp[0]);
	new->value = ft_strjoin("=", tmp[1]);
	new->index = 0;
	new->next = NULL;
	first_node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (first_node->next != NULL)
		first_node = first_node->next;
	first_node->next = new;
}

void	start_env(t_data *d, char **env)
{
	char	**tmp;

	d->envp = ft_calloc(1, sizeof(t_env));
	if (!d->envp)
		return ;
	tmp = ft_split(env[d->j], '=');
	if (!tmp)
		return ;
	d->envp->key = ft_strdup(tmp[0]);
	d->envp->value = ft_strjoin("=", tmp[1]);
	d->envp->index = 0;
	d->envp->next = NULL;
	free_tmp(tmp);
	while (env[++d->j])
	{
		d->aux = ft_calloc(1, sizeof(t_env));
		if (!d->aux)
			return ;
		tmp = ft_split(env[d->j], '=');
		if (!tmp)
			return ;
		lst_addenv_back(&d->envp, d->aux, tmp);
		free_tmp(tmp);
	}
}
