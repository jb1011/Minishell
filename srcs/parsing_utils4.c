/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/23 17:19:26 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	replace_inib_space(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			count++;
		if (str[i] == ' ' && (count % 2 != 0))
			str[i] = '`';
		i++;
	}
}

int	is_only_space(char *s, int start)
{
	start++;
	while (s[start])
	{
		if (is_char_separator(s[start]))
		{
			return (1);
		}
		if (s[start] != ' ')
			return (0);
		start++;
	}
	return (1);
}

void	count_and_malloc(t_all *all, char *str)
{
	int	i;

	all->count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			all->count++;
		i++;
	}
	all->pipendirect = malloc(sizeof(char) * all->count + 2);
}
