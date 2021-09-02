/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/02 02:07:58 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_split(char *line)
{
	int i;
	int count;

	count = 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == ';')
			count++;
		i++;
	}
	return (count);
}

int	ft_count_spaces(char *line)
{
	int i;
	int count;

	count = 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	parse_line(t_all *all)
{
	int j;
	char	*tmp;

	j = 0;
	if (!ft_strchr(all->line, ';') && !ft_strchr(all->line, '|'))
	{
		if (ft_strchr(all->line, ' '))
		{
			all->w_line = malloc(sizeof(char **) * ft_count_spaces(all->line) + 1);
			all->w_line[0] = ft_split(all->line, ' ');
			all->w_line[1] = 0;
			trim_tab(all->w_line);
			// ft_print_megatab(all->w_line);
		}
		else
		{
			all->w_line = malloc(sizeof(char **) * 2);
			all->w_line[0] = (char **)malloc(sizeof(char *) * 2);
			all->w_line[0][0] = ft_strdup(all->line);
			all->w_line[0][1] = 0;
			all->w_line[1] = 0;
			trim_tab(all->w_line);
			// ft_print_megatab(all->w_line);
		}
	}
	if (ft_strchr(all->line, '|'))
	{
		all->w_line = malloc(sizeof(char **) * ft_count_split(all->line) + 1);
		all->splt_line = ft_split(all->line, ';');
		while (all->splt_line[j])
		{
			all->w_line[j] = ft_split(all->splt_line[j], '|');
			j++;
		}
		all->w_line[j] = 0;
		ft_free_tab(all->splt_line);
		trim_tab(all->w_line);
		// ft_print_megatab(all->w_line);

	}
	if (!ft_strchr(all->line, '|') && ft_strchr(all->line, ';'))
	{
		all->w_line = malloc(sizeof(char **) * ft_count_split(all->line) + 1);
		all->w_line[0] = ft_split(all->line, ';');
		all->w_line[1] = 0;
		trim_tab(all->w_line);
		// ft_print_megatab(all->w_line);
	}

	if (!all->w_line)
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
