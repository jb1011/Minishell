/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/02 13:17:28 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	replace_inib_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		if (str[i] == ' ' && (count % 2 != 0))
			str[i] = '`';
		i++;
	}
}

void	replace_back_inib_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		if (str[i] == '`' && (count % 2 != 0))
		{
			str[i] = ' ';
		}
		i++;
	}
}

void	replace_doubleback_inib_space(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '`')
				str[j][i] = ' ';
			i++;
		}
		j++;
	}
}


void	replace_crocs(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && !quote_is_odd(str, i))
			str[i] = '|';
		i++;
	}
}

void	replace_double_croc(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<' && s[i + 1] == '<')
		{
			s[i] = '|';
			s[i + 1] = ' ';
		}
		if (s[i] == '>' && s[i + 1] == '>')
		{
			s[i] = '|';
			s[i + 1] = ' ';
		}
		i++;
	}
	// printf("line replaced : %s\n", s);
}
