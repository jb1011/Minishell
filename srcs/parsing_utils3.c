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
