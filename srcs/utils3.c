/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting&ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/08/30 21:47:51 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_get_nb_strs(char *s, char c)
{
	int	i;
	int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

int	is_separator(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '>' || s[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

int	is_char_separator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	quote_is_odd(char *s, int end)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < end)
	{
		if (s[i] == '\'')
			count ++;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}
