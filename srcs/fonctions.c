/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:32:32 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 14:57:11 by lgelinet         ###   ########.fr       */
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


int	_fct(t_all *all,char *todo[], int std[2])
{
	int		k;
	pid_t	id;
	int	realfd[2];
	char **env = NULL;

	if (!assign(&k, is_builtins(todo)) && !isfct(all->exec_paths, todo))
	{
		multclose(std[0], std[1]); 
		return (-1);
	}
	if (!k)
		env = env_to_strtab(all->env);
	realfd[0] = dup(0);
	realfd[1] = dup(1);
	dup2(std[0], 0);
	dup2(std[1], 1);
	if (k)
	{
		if (!do_builtins(all, todo, k))
			g_status = 1;
		else
			g_status = 0;
	}	
	else if (!assign(&id, fork()))
		execve(*todo, todo, env);
	else
	{
		waitpid(id , &k, 0);
		g_status = WEXITSTATUS(k);
	}
	free_doubletab(env);
	multclose(std[0], std[1]);
	dup2(realfd[0],0);
	dup2(realfd[1],1);
	return (1);
}

