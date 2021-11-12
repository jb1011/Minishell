/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/11 14:04:31 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parse_line(t_all *all)
{
	all->pipelist = NULL;
	if (all->line)
	{
		free_list(&all->pipelist);
		ft_count_pipes(all);
		all->line = ignore_quote(all->line);
		replace_inib_space(all->line);
		is_pipe_inhib(all->line);
		init_list_var(all);
		replace_double_croc(all->line);
		if (!ft_check_error(all->line))
		{
			printf("Parse Error\n");
			free_list(&all->pipelist);
		}
	}
	return (1);
}

void	init_list_var(t_all *all)
{
	int	i;

	i = 0;
	all->splt_line = ft_split(all->line, '|');
	while (all->splt_line[i])
	{
		split_redir(all, all->splt_line[i]);
		split_target(all, all->splt_line[i]);
		split_orders(all, all->splt_line[i]);
		replace_doubleback_inib_space(all->order_cpy);
		replace_doubleback_inib_space(all->target_cpy);
		reverse_pipe(all->target_cpy);
		reverse_pipe(all->order_cpy);
		addnew(all, all->order_cpy, all->target_cpy, all->redir_cpy);
		free_doubletab(all->order_cpy);
		free_doubletab(all->target_cpy);
		free_doubletab(all->redir_cpy);
		i++;
	}
	ft_free_tab(all->splt_line);
}

void	split_redir(t_all *all, char *str)
{
	int	i;

	i = 0;
	count_pipe_croc(str, all);
	all->size_redir = ft_strlen(all->pipendirect);
	all->redir_cpy = malloc(sizeof(char *) * (all->size_redir + 1));
	while (all->pipendirect[i])
	{
		all->redir_cpy[i] = malloc(sizeof(char) * 2);
		all->redir_cpy[i][0] = all->pipendirect[i];
		all->redir_cpy[i][1] = 0;
		i++;
	}
	all->redir_cpy[i] = 0;
	free(all->pipendirect);
}

void	split_target(t_all *all, char *str)
{
	if (is_separator(str))
	{
		if (ft_count_redir(str) == 1)
			split_target2(all, str);
		else if (ft_count_redir(str) > 1)
			split_target3(all, str);
	}
	else
	{
		all->target_cpy = malloc(sizeof(char *) * 1);
		all->target_cpy[0] = 0;
	}
}

void	split_orders(t_all *all, char *str)
{
	int	i;

	all->to_free = (ft_get_nb_strs(str, ' '));
	i = 0;
	if (!is_redir_str(str))
	{
		all->tmp = ft_strdup(str);
		all->order_cpy = ft_split(all->tmp, ' ');
		free(all->tmp);
		return ;
	}
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
			str[i] = ' ';
		i++;
	}
	all->order_cpy = ft_split(str, ' ');
}
