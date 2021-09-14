/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:32:32 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/13 18:01:26 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*En gros fork() lance un processus fils avec un pid = 0 ,
vu aue la fonction execve() stop le programme on envoie le fils le faire"*/
int	_fct(char *todo[], char *env[], int stdin , int stdout)
{
	int		i;
	pid_t	id;

	
	id = fork();
	if (id) // si c'est pas le processus fils , on attend aue le processus fils se finisse
	 	waitpid(id, 0, 0);
	else
	{
		dup2(stdin,0);
		dup2(stdout, 1);
		execve(*todo, todo, env);
		 // le bin ou le nom du fichier todo0 la suite de todo c'est les params , env on verra apres
	}
	i = 0;
	if (!env)
		return (1);
	// printf("pre free env fct \n");
	// while (env[++i])
		// free(env[i]);
	// free(env[i]);
	// free(env);
	// printf("post free env fct \n");
	return (1);
}

