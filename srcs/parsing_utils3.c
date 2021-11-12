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

void	replace_doubleback_inib_space(char **str)
{
	int	i;
	int	j;

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

char	*ignore_quote(char *str)
{
	int		i;
	char	*tmp;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"')
			count++;
		if (((str[i] == '\'' && str[i - 1] == '`')
				|| (str[i] == '"' && str[i - 1] == '`')) && (count % 2 == 0))
			str[i] = '`';
		if (((str[i] == '\'' && str[i + 1] == '\'')
				|| (str[i] == '"' && str[i + 1] == '"')) && (count % 2 == 0))
			str[i] = '`';
		i++;
	}
	tmp = ft_dup(str, '`');
	free(str);
	return (tmp);
}

void	rpl_space(char *str, int start, int len)
{
	while (len > 0)
	{
		str[start] = ' ';
		start++;
		len--;
	}
}

void	split_target2(t_all *all, char *str)
{
	t_slv	s;

	s = (t_slv){0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (str[s.i])
	{
		if (str[s.i] == '>' || str[s.i] == '<')
		{
			if (is_redir(str[s.i + 1]))
				s.i++;
			s.k = s.i;
			s.i++;
			while (str[s.i] == ' ')
				s.i++;
			while (str[s.i + 1] != 0 && str[s.i + 1] != ' ')
				s.i++;
			s.la = s.i - s.k;
			s.k++;
			all->tmp = ft_substr(str, s.k, s.la);
			rpl_space(str, s.k, s.la);
		}
		if (s.i < ft_strlen(str))
			s.i++;
	}
	all->target_cpy = ft_split(all->tmp, ' ');
	free(all->tmp);
}

void	split_target3(t_all *all, char *str)
{
	t_slv	s;

	s = (t_slv){-1, 0, 0, 0, 0, 0, 0, 0, 0};
	all->target_cpy = malloc(sizeof(char *) * (all->size_redir + 1));
	while (str[++s.i])
	{
		if (str[s.i] == '>' || str[s.i] == '<')
		{
			if (is_redir(str[s.i + 1]))
				s.i++;
			s.k = s.i;
			s.i++;
			while (str[s.i] == ' ')
				s.i++;
			while (str[s.i + 1] != 0 && str[s.i + 1] != ' '
				&& str[s.i + 1] != '>' && str[s.i + 1] != '<')
				s.i++;
			s.la = s.i - s.k;
			s.k++;
			all->target_cpy[s.j] = ft_substr(str, s.k, s.la);
			rpl_space(str, s.k, s.la);
			s.j++;
		}
	}
	all->target_cpy[s.j] = 0;
}
