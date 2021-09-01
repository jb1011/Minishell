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

int	ft_count_split(char *line)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == ';')
			count++;
		i++;
	}
	return (count + 1);
}

int	parse_line(t_all *all)
{
	int j;

	all->w_line = malloc(sizeof(char **) * ft_count_split(all->line) + 1);
	j = 0;
	if (ft_strchr(all->line, '|'))
	{
		all->splt_line = ft_split(all->line, ';');
		while (all->splt_line[j])
		{
			all->w_line[j] = ft_split(all->splt_line[j], '|');
			j++;
		}
		all->w_line[j] = 0;
		ft_free_tab(all->splt_line);
	}
	else
	{
		all->w_line[0] = ft_split(all->line, ';');
		all->w_line[1] = 0;
	}
	trim_tab(all->w_line);

	ft_print_megatab(all->w_line);
	ft_free_megatab(all->w_line);
	return (1);
}

void	trim_tab(char ***t)
{
	int j;
	int i;
	char	*tmp;

	j = 0;
	while (t[j])
	{
		i = 0;
		while (t[j][i])
		{
			if (ft_strchr(t[j][i], ' '))
			{
				tmp = ft_strtrim(t[j][i], " ");
				free(t[j][i]);
				t[j][i] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
}