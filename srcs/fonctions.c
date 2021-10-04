/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:32:32 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/04 13:17:17 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>

/*En gros fork() lance un processus fils avec un pid = 0 ,
vu aue la fonction execve() stop le programme on envoie le fils le faire"*/
int	multclose(int stdin, int stdout)
{
	if (stdin)
		close (stdin);
	if (stdout != 1)
		close (stdout);
	return (0);
}


int	_fct(t_all *all,char *todo[], char *env[], int stdin , int stdout)
{
	int		k;
	pid_t	id;
	int	realfd[2];

	if (!assign(&k, is_builtins(todo)) && !isfct(all->exec_paths, todo))
	{
		multclose(stdin, stdout); 
		return (ft_err_msg("Error :unknown function\n"));
	}
	realfd[0] = dup(0);
	realfd[1] = dup(1);
	dup2(stdin,0);
	dup2(stdout,1);
	if (k)
		do_builtins(all, todo, k);
	else if (!assign(&id, fork()))
		execve(*todo, todo, env);
	else
	 	waitpid(id , 0, 0);
	multclose(stdin, stdout);
	dup2(realfd[0],0);
	dup2(realfd[1],1);
	return (1);
}

