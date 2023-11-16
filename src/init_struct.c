/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:45:46 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/15 17:48:41 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_struct(t_data *d)
{
	d->env = NULL;
	d->tmp = NULL;
	d->tmp1 = NULL;
	d->shell = NULL;
	d->cmds = NULL;
	d->i = 0;
}
