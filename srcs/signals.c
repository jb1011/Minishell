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
	if (signum == SIGINT)
	{
		ft_putstr("\n");
		ft_bzero(all->path, BUFFER_SIZE);
		getcwd(all->path, BUFFER_SIZE - 1);
		printf("%s %s-> ", all->path, SHELL_PROMPT);
	}
	if (signum == SIGQUIT)
	{
		_myexit(all);
		// ft_putstr("\n");
	}
}