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

void	ft_free_tab(char **t)
{
	int j;

	j = 0;
	if (t)
	{
		while (t[j])
		{
			free(t[j]);
			j++;
		}
		free(t);
		t = NULL;
	}
}

void	ft_free_order(char **t, t_all *all)
{
	int j;

	j = 0;
			// ft_putnbr_fd(all->to_free,0);

	if (t)
	{
		while (j < all->to_free)
		{
			// ft_putnbr_fd(j,0);
			free(t[j]);
			j++;
		}
		free(t);
		t = NULL;
	}
}

void	ft_free_megatab(char ***t)
{
	int j;

	j = 0;
	if (t[j])
	{
		while (t[j])
		{
			ft_free_tab(t[j]);
			j++;
		}
	}
	free(t);
}

void	free_for_all(t_all *all)
{
	if (all->order_cpy)
		ft_free_tab(all->order_cpy);
	if (all->target_cpy)
		ft_free_tab(all->target_cpy);
	if (all->redir_cpy)
		ft_free_tab(all->redir_cpy);
	if (all->splt_line)
		ft_free_tab(all->splt_line);
	if (all->tmp)
		free(all->tmp);
	if (all->line)
		free(all->line);
}