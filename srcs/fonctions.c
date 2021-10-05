/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:32:32 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 16:34:12 by lgelinet         ###   ########.fr       */
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
	return (-1);
}

int	forkexec(char **todo, t_env *list)
{
	int		id;
	int		stat;
	char	env;

	env = env_to_strtab(list);
	id = fork();
	if (!id)
		execve(*todo, todo, env);
	else
	{
		waitpid(id, &stat, 0);
		status = WEXITSTATUS(stat);
	}
	free_doubletab(env);
}

int	_fct(t_all *all, char *todo[], int std[2])
{
	int		k;
	int		realfd[2];

	if (!assign(&k, is_builtins(todo)) && !isfct(all->exec_paths, todo))
		return (multclose(std[0], std[1]));
	realfd[0] = dup(0);
	realfd[1] = dup(1);
	dup2(std[0], 0);
	dup2(std[1], 1);
	if (k)
	{
		if (!do_builtins(all, todo, k))
			status = 1;
		else
			status = 0;
	}	
	else
		forkexec(todo, all->env);
	multclose(std[0], std[1]);
	dup2(realfd[0], 0);
	dup2(realfd[1], 1);
	return (1);
}
