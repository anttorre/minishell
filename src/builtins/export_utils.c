/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:29:10 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/28 16:58:42 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	del_node(t_env **first_node, t_env *new)
{
	free((*first_node)->value);
	(*first_node)->value = ft_strdup(new->value);
	/* free((*new)->key);
	free((*new)->value);
	free(new); */
}

void	lst_addexport_back(t_env **lst, t_env *new, char **tmp)
{
	t_env	*first_node;
	t_env	*to_update;
	int		flag_node;

	flag_node = 0;
	if (new == NULL)
		return ;
	if (tmp != NULL)
	{
		new->key = ft_strdup(tmp[0]);
		new->value = ft_strjoin("=", tmp[1]);
		new->index = 0;
		new->next = NULL;
	}
	first_node = *lst;
	to_update = ft_calloc(1, sizeof(t_env));
	if (!to_update)
		return ;
	to_update->key = ft_strdup(new->key);
	to_update->value = ft_strdup(new->value);
	to_update->index = 0;
	to_update->next = NULL;
	if (*lst == NULL)
	{
		*lst = to_update;
		return ;
	}
	if (tmp == NULL)
	{
		while (first_node != NULL)
		{
			if (!ft_strncmp(to_update->key, first_node->key, ft_strlen(first_node->key)))
			{
				del_node(&first_node, to_update);
				flag_node = 1;
				break ;
			}
			first_node = first_node->next;
		}
		if (flag_node != 1)
			first_node = to_update;
	}
	else
	{
		while (first_node->next != NULL)
			first_node = first_node->next;
		first_node->next = to_update;
	}
}

t_env	*get_max(t_data *d)
{
	t_env	*aux;
	t_env	*max;

	aux = d->envp;
	max = d->envp;
	while (aux)
	{
		if (ft_strncmp(aux->key, max->key, ft_strlen(aux->key) + 1)
			> 0 && aux->index == 0)
			max = aux;
		aux = aux->next;
	}
	return (max);
}

void	set_index_export(t_data *d)
{
	t_env	*lower;
	t_env	*aux;
	int		i;

	i = 1;
	restart_index(&d->envp);
	lower = d->envp;
	aux = d->envp;
	while (i <= lstsize_env(d->envp))
	{
		while (aux)
		{
			if (ft_strncmp(aux->key, lower->key, ft_strlen(aux->key) + 1)
				< 0 && aux->index == 0)
				lower = aux;
			aux = aux->next;
		}
		lower->index = i++;
		aux = d->envp;
		lower = get_max(d);
	}
}

int	add_vars(char *s, t_data *d)
{
	char	**tmp;
	int		i;
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (EXIT_FAILURE);
	i = 0;
	while (s[i])
	{
		if (s[i - 1] != ' ' && s[i] == '=')
		{
			tmp = ft_split(s, '=');
			if (!tmp)
				return (EXIT_FAILURE);
			lst_addexport_back(&d->export, new, tmp);
			free_tmp(tmp);
			break ;
		}
		if (s[i - 1] == ' ' && s[i] == '=')
			break ;
		i++;
	}
	return (EXIT_SUCCESS);
}
