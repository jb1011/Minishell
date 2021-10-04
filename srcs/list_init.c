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

	cell = createCell(orders, targets, redir);
	if (is_empty(all->pipelist))
	{
		all->pipelist = cell;
		return ;
	}
	cell->next = all->pipelist;
	all->pipelist = cell;
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

void	free_list(t_pipenodes **st)
{
	t_pipenodes	*to_del;

	if (st && *st)
	{
		while (*st)
		{
			to_del = *st;
			free_doubletab(to_del->orders);
			free_doubletab(to_del->redir);

			free_doubletab(to_del->targets);

			// ft_free_tab(to_del->orders);
			// ft_free_tab(to_del->redir);
			// ft_free_tab(to_del->targets);
			*st = (*st)->next;
			free(to_del);
		}
		*st = NULL;
	}
}