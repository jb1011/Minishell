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
	cell->orders = orders; 
	cell->list_of_redirections = redir;
	cell->list_of_targets = targets;
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
		printf("ORDERS :\n");
		ft_print_tab(stack->orders);
		printf("REDIRECTION :\n");
		ft_print_tab(stack->list_of_redirections);
		printf("TARGETS :\n");
		ft_print_tab(stack->list_of_targets);
		tmp = tmp->next;
	}
	ft_putstr("\n");
}