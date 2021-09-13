/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:00:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/13 18:00:07 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int		redirect_fcts(char **redirections, char **targets, char *todo[], char *env[])
{
	int	i;
	int id;
	int stdout;
	int stdin;

	i = -1;
	stdout = 1;
	stdin = 0;
	if (!redirections)
		return (_fct(todo, env, 0, 1));
	while (targets[++i])
	{
		if (redirections[i][0] == 'g')
			stdout = open(targets[i],O_CREAT | O_WRONLY |  O_APPEND, S_IRUSR | S_IWUSR);
		else if (redirections[i][0] == 'p')
			printf("CEST PAS ENCORE AU POINT");
		else if (redirections[i][0] == '>')
			stdout = open(targets[i],O_CREAT | O_WRONLY |  O_TRUNC, S_IRUSR | S_IWUSR);
		else
			stdin = open(targets[i],O_RDONLY, S_IRUSR | S_IWUSR);
		_fct(todo, env, stdin, stdout);
		if (stdin > 2)
			close(stdin);
		if (stdout > 2)
			close(stdout);
		stdout = 1;
		stdin = 0;
	}
    return (1);
}