/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:32:32 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/14 17:12:42 by lgelinet         ###   ########.fr       */
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
	int		i;
	pid_t	id;
	int		temp[2];

	//fd[o] = read
	//fd[1] = write
	if (!is_builtins(all, todo) && !isfct(all->exec_paths, todo))
	{
		multclose(stdin, stdout); 
		return (ft_err_msg("Error , unknown function\n"));
	}
	id = fork();
	if (id) // si c'est pas le processus fils , on attend aue le processus fils se finisse
	 	waitpid(id , 0, 0);
	else
	{
		dup2(stdin,0);
		dup2(stdout, 1);
		if (!do_builtins(all, todo))
			execve(*todo, todo, env);
		exit (1);
		 // le bin ou le nom du fichier todo0 la suite de todo c'est les params , env on verra apres
	}
	multclose(stdin, stdout);
	if (!env)
		return (1);
	return (1);
}

