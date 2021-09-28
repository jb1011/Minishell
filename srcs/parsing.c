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

int	parse_line(t_all *all)
{
	all->pipelist = NULL;
	free_list(all->pipelist);
	ft_count_pipes(all);
	all->line = ignore_quote(all->line);
	replace_inib_space(all->line);
	is_pipe_inhib(all->line);
	init_list_var(all);
	replace_double_croc(all->line);
	if (!ft_check_error(all->line))
		printf("ERRRROOROOOOOOORRRRR");
	return (1);
}

void	init_list_var(t_all *all)
{
	int	i;

	all->pipelist = NULL;
	free_list(all->pipelist);
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
		// ft_free_order(all->order_cpy, all);
		ft_free_tab(all->order_cpy);
		ft_free_tab(all->target_cpy);
		ft_free_tab(all->redir_cpy);
		i++;
	}
	ft_free_tab(all->splt_line);
	// print_linked_list(all->pipelist);
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
	int	i;
	int	j;
	int start;
	int	len;

	if (is_separator(str))
	{
		all->target_cpy = malloc(sizeof(char *) * (all->size_redir + 1));
		i = 0;
		j = 0;
		if (ft_count_redir(str) == 1)
		{
			while (str[i])
			{
				if (str[i] == '>' || str[i] == '<')
				{
					if (is_redir(str[i + 1]))
						i++;
					start = i;
					i++;
					while (str[i] == ' ')
						i++;
					while (str[i + 1] != 0 && str[i + 1] != ' ')
						i++;
					len = i - start;
					start++;
					all->tmp = ft_substr(str, start, len);
					j++;
					rpl_space(str, start, len);
				}
				if (i < ft_strlen(str))
					i++;
			}
			all->target_cpy = ft_split(all->tmp, ' ');
			free(all->tmp);
		}
		else if (ft_count_redir(str) > 1)
		{
			while (str[i])
			{
				if (str[i] == '>' || str[i] == '<')
				{
					if (is_redir(str[i + 1]))
						i++;
					start = i;
					i++;
					while (str[i] == ' ')
						i++;
					while (str[i + 1] != 0 && str[i + 1] != ' ' && str[i + 1] != '>' && str[i + 1] != '<')
						i++;
					len = i - start;
					start++;
					all->target_cpy[j] = ft_substr(str, start, len);
					rpl_space(str, start, len);
					j++;
				}
				if (i < ft_strlen(str))
					i++;
			}
			all->target_cpy[j] = 0;
		}
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
	all->order_cpy = malloc(sizeof(char *) * all->to_free);
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
