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

void count_pipe_croc(char *str, t_all *all)
{
	int i;
	int count;
	int j;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			count++;
		i++;
	}
	all->pipendirect = malloc(sizeof(char) * count + 2);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!quote_is_odd(str, i))
		{
			if (str[i] == '<' && str[i + 1] == '<')
			{
				all->pipendirect[j] = 'p';
				j++;
				i++;
			}
			if (str[i] == '>' && str[i + 1] == '>')
			{
				all->pipendirect[j] = 'g';
				j++;
				i++;
			}
			if (str[i] == '<')
			{
				if (str[i - 1] != '<')
				{
					all->pipendirect[j] = str[i];
					j++;
				}
			}
			if (str[i] == '>')
			{
				if (str[i - 1] != '>')
				{
					all->pipendirect[j] = str[i];
					j++;
				}
			}
		}
		i++;
	}
	all->pipendirect[j] = 0;
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
			if (str[j][i] == '@')
				str[j][i] = '|';
			i++;
		}
		j++;
	}
}

int	ft_check_error(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!quote_is_odd(s, i))
		{
			if (s[i] == '|' && s[i + 1] == '|')
				return (0);
			if (is_char_separator(s[i]))
				if (is_only_space(s, i))
				{
				printf("########");
				return (0);
			}
		}
		i++;
	}
	return (1);
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
}