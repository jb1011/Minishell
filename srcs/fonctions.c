/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:32:32 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/09 15:00:01 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*En gros fork() lance un processus fils avec un pid = 0 ,
vu aue la fonction execve() stop le programme on envoie le fils le faire"*/
int	_fct(char *todo[], char *env[])
{
	int		i;
	pid_t	id;

	id = fork();
	if (id) // si c'est pas le processus fils , on attend aue le processus fils se finisse
	 	waitpid(id, 0, 0);
	else
		execve(*todo, todo, env); // le bin ou le nom du fichier todo0 la suite de todo c'est les params , env on verra apres
	if (!id)
	{ // Si le fils est tjr la c'est au'il y'a erreur
		printf("Error, wrong file/function\n");
		close(id);
		return(-1);
	}
	i = 0;
	if (!env)
		return (1);
	while (env[++i])
		free(env[i]);
	free(env[i]);
	free(env);
	return (1);
}
