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

int	is_pipe_inhib(char *str)
{
	int i;
	int count;
	int	count2;

	count = 0;
	count2 = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		if (str[i] == '"')
			count2++;
		if (str[i] == '|' && ((count2 % 2 != 0) || (count % 2 != 0)))
			str[i] = '^';
		i++;
	}
	return (1);
}

void reverse_pipe(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '^')
				str[j][i] = '|';
			i++;
		}
		j++;
	}
}

void	replace_quote(char *str)
{
	int	i;
	int mybol;

	i = 0;
	mybol = 0;
	while (str[i])
	{
		if (mybol)
		{
			str[i] = ' ';
			mybol = 0;
		}
		if (str[i] == '\'' && str[i + 1] == '\'')
		{
			str[i] = ' ';
			mybol = 1;
		}
		if (str[i] == '"' && str[i + 1] == '"')
		{
			str[i] = ' ';
			mybol = 1;
		}
		i++;
	}
}
