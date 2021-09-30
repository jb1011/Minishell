/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/30 11:59:27 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sigint(int signum, t_all *all)
{
	if (signum == SIGINT)
	{
		ft_putstr("\n");
		ft_bzero(all->path, BUFFER_SIZE - 1);
		getcwd(all->path, BUFFER_SIZE - 1);
		printf("%s %s-> \n", all->path, SHELL_PROMPT);
	}
	if (signum == SIGQUIT)
	{
		_myexit(all);
		// ft_putstr("\n");
	}
}