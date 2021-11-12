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

void	double_croc_left(t_all *all)
{
	all->pipendirect[all->j] = 'p';
	all->j++;
	all->i++;
}

void	double_croc_right(t_all *all)
{
	all->pipendirect[all->j] = 'g';
	all->j++;
	all->i++;
}

void	double_croc_skip_left(t_all *all, char *str)
{
	all->pipendirect[all->j] = str[all->i];
	all->j++;
}

void	double_croc_skip_right(t_all *all, char *str)
{
	all->pipendirect[all->j] = str[all->i];
	all->j++;
}
