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

int	is_empty(t_pipenodes *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

void	addnew(t_all *all, char **orders, char **targets, char **redir)
{
	t_pipenodes *cell;
	t_pipenodes *tmp;

	cell = createCell(orders, targets, redir);
	if (is_empty(all->stack))
	{
		all->stack = cell;
		return ;
	}
	tmp = all->stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = cell;
}

void	print_linked_list(t_pipenodes *stack)
{
	t_pipenodes	*tmp;

	tmp = stack;
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

	tmp = st->orders;
	if (!is_empty(tmp))
	{
		while (tmp)
		{
			to_del = tmp;
			tmp = tmp->next;
			free(to_del);
		}
	}
	st->orders = NULL;
}