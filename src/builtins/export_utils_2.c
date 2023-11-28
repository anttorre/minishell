/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:05:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/28 13:08:18 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	restart_index(t_env	**lst)
{
	t_env	*aux;

	if (!lst)
		return ;
	aux = *lst;
	while (aux)
	{
		aux->index = 0;
		aux = aux->next;
	}
}
