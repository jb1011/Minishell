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

int	ft_count_split(char *line)
{
	int i;
	int count;
	int c;

	count = 1;
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			c++;
		if ((line[i] == '|' || line[i] == '<' || line[i] == '>') && (c % 2 == 0))
			count++;
		i++;
	}
	return (count + 1);
}

int ft_count_pipes(t_all *all)
{
	int i;
	int c;

	all->count_list = 1;
	i = 0;
	c = 0;
	while (all->line[i])
	{
		if (all->line[i] == '\'')
			c++;
		if ((all->line[i] == '|') && (c % 2 == 0))
			all->count_list += 1;
		i++;
	}
	return (all->count_list);
}

int	ft_count_redir(char *line)
{
	int i;
	int count;
	int c;

	count = 0;
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			c++;
		if ((line[i] == '<' || line[i] == '>') && (c % 2 == 0))
			count++;
		i++;
	}
	return (count);
}
int	ft_count_space(char *line)
{
	int i;
	int count;
	int c;

	count = 1;
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			c++;
		if ((line[i] == ' ') && (c % 2 == 0))
			count++;
		i++;
	}
	return (count + 1);
}

int	is_pipe_inhib(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			count++;
		if (str[i] == '|' && (count % 2 != 0))
			str[i] = '@';
		i++;
	}
	return (1);
}
