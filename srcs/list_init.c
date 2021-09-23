/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/23 17:19:26 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pipenodes	*createCell(char **orders, char **targets, char **redir)
{
	t_pipenodes *cell;

	cell = malloc(sizeof(t_pipenodes));
	if (!cell)
		return (NULL);
	cell->orders = mall_doubletab(orders);
	cell->redir = mall_doubletab(redir);
	cell->targets = mall_doubletab(targets);
	cell->next = NULL;
	return (cell);
}

int	is_empty(t_pipenodes *pipelist)
{
	if (pipelist == NULL)
		return (1);
	return (0);
}

void	addnew(t_all *all, char **orders, char **targets, char **redir)
{
	t_pipenodes *cell;
	t_pipenodes *tmp;

	cell = createCell(orders, targets, redir);
	if (is_empty(all->pipelist))
	{
		all->pipelist = cell;
		return ;
	}
	tmp = all->pipelist;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = cell;
}

void	print_linked_list(t_pipenodes *pipelist)
{
	t_pipenodes	*tmp;

	tmp = pipelist;
	while (tmp)
	{
		ft_putstr("===============\n");
		printf("ORDERS :\n");
		if (tmp->orders)
			ft_print_tab(tmp->orders);
		printf("REDIRECTION :\n");
		if (tmp->redir)
			ft_print_tab(tmp->redir);
		printf("TARGETS :\n");
		if (tmp->targets)
			ft_print_tab(tmp->targets);
		ft_putstr("===============\n");
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

void	free_list(t_pipenodes *st)
{
	t_pipenodes	*tmp;
	t_pipenodes	*to_del;

	tmp = st;
	if (!is_empty(st))
	{
		while (st)
		{
			to_del = st;
			st = st->next;
			free(to_del);
		}
	}
	st = NULL;
}