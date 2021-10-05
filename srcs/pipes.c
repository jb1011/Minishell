/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:11:42 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 16:47:49 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	piping(t_all *all, t_env *env, t_pipenodes *nd)
{
	int	id;
	int	fd[2];
	int	real_in;

	if (all->count_list == 1 || !nd->next)
		return (treat_orders(all, nd));
	pipe(fd);
	if (!(assign(&id, fork())))
	{
		close(fd[0]);
		dup2(fd[1], 1);
		piping(all, env, nd->next);
		close(fd[1]);
		close (1);
		exit(1);
	}
	close (fd[1]);
	waitpid(id, 0 , 0);
	real_in = dup(0);
	dup2(fd[0],0);
	treat_orders(all, nd);
	close(fd[0]);
	dup2(real_in,0);
	return (1);
}