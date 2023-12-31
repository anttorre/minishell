/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:21:43 by anttorre          #+#    #+#             */
/*   Updated: 2023/11/13 13:15:03 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_split_quotes(char **arr)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

static void	iterator_quotes(char **str, char d, char *aux, int *flag_quote)
{
	if (**str == '|' || **str == ';')
		(*str)++;
	while ((**str == d || **str == '\'' || **str == '\"') && **str != '\0')
	{
		if (**str == '\'' || **str == '\"')
		{
			*aux = **str;
			*flag_quote = !*flag_quote;
		}
		(*str)++;
	}
}

size_t	words_count(char *str, char d)
{
	size_t	count;
	int		flag_quote;
	char	aux;

	count = 0;
	flag_quote = 0;
	while (*str)
	{
		if (*str == '|' || *str == ';')
			str++;
		iterator_quotes(&str, d, &aux, &flag_quote);
		if (*str != '\'' && *str != '\"' && *str != d)
			count++;
		if (flag_quote)
			while (*str != aux && *str)
				str++;
		else
			while (*str != d && *str && *str != '|')
				str++;
	}
	return (count);
}

int	word_length(char *str, char d, int flag, char c)
{
	int		flag_quote[2];
	char	aux;

	flag_quote[0] = flag;
	flag_quote[1] = 0;
	aux = c;
	if (flag_quote[0])
	{
		while (*str != aux && *str)
		{
			flag_quote[1]++;
			str++;
		}
	}
	else
	{
		while (*str != d && *str && *str != '|' && *str != ';')
		{
			flag_quote[1]++;
			str++;
		}
	}
	return (flag_quote[1]);
}

char	**split_loop(char *s, char d, t_data *data)
{
	char	**new_str;
	int		flag_quote;
	char	aux;
	int		wl;

	data->i = -1;
	flag_quote = 0;
	new_str = ft_calloc(words_count(s, d) + 1, sizeof(char *));
	if (!new_str)
		return (NULL);
	while (*s)
	{
		iterator_quotes(&s, d, &aux, &flag_quote);
		while ((*s != aux && flag_quote)
			|| (*s != d && !flag_quote && *s && *s != '|' && *s != ';'))
		{
			wl = word_length(s, d, flag_quote, aux);
			new_str[++data->i] = ft_calloc(wl + 1, sizeof(char));
			if (!new_str[data->i])
				return (free_split_quotes(new_str), NULL);
			ft_strlcpy(new_str[data->i], s, wl + 1);
			s += wl;
		}
	}
	return (new_str[++data->i] = NULL, data->i = 0, new_str);
}
