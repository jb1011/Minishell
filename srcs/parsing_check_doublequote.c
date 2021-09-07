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

int	db_quote_open(char *str, int end)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(i < end)
	{
		if (str[i] == '"')
			count ++;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}

void	trim_quote(char ***t)
{
	int	i;
	int	j;
	char	*tmp;

	j = 0;
	while (t[j])
	{
		i = 0;
		while (t[j][i])
		{
			if (t[j][i][0] == '"')
			{
				tmp = ft_strtrim(t[j][i], "\"");
				free(t[j][i]);
				t[j][i] = ft_strdup(tmp);
				free(tmp);
			}
			if (t[j][i][0] == '\'')
			{
				tmp = ft_strtrim(t[j][i], "\'");
				free(t[j][i]);
				t[j][i] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
}