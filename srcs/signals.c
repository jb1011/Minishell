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

void	ft_sigint(int signum, t_all *all)
{
	int id;

	if (signum == SIGINT)
	{
		all->ctrl_c = 1;
		if (!assign(&id, fork()))
		{
			sleep(0.5);
			dup2(0,1);
			dup2(2, 0);
			ft_putstr("\n");
			close (1);
			close(0);
			exit(1);
		}
	}
	if (signum == SIGQUIT)
	{
		// _myexit(all);
		exit (1);
		// ft_putstr("\n");
	}
}