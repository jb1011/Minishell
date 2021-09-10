/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:00:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/10 18:23:28 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int		redirect_fcts(char **redirections, char **targets, char *todo[], char *env[])
{
	int	i;
	int id;
	int c;

	i = -1;
	if (!redirections)
		return (_fct(todo, env));
	while (targets[++i])
	{
		if (redirections[i][0] == 'g')
			c = open(targets[i],O_CREAT | O_WRONLY |  O_APPEND, S_IRUSR | S_IWUSR);
		else if (redirections[i][0] == 'p')
			printf("CEST PAS ENCORE AU POINT");
		else
			c = open(targets[i],O_CREAT | O_WRONLY |  O_TRUNC, S_IRUSR | S_IWUSR);
		id = fork();
		if (!id)
		{
			dup2(c, 1);
			_fct(todo, env);
			close(c);
			close (id);
            return (-1);
		}
		else 
			waitpid(id, 0, 0);
	}
    return (1);
}