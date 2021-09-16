/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:00:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/14 17:17:45 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <fcntl.h>
#include <readline/readline.h>


int		redirect_fcts(char **redirections, char **targets, char *todo[], char *env[])
{
	int	i;
	int id;
	int stdout;
	int stdin;
	char	*buff;
	char	*str = NULL;
	int		size;

	i = -1;
	stdout = 1;
	stdin = 0;
	if (!redirections)
		return (_fct(todo, env, 0, 1, 0));
	while (targets[++i])
	{
		printf ("in the loop redir\n");
		if (redirections[i][0] == 'g')
			stdout = open(targets[i],O_CREAT | O_WRONLY |  O_APPEND, S_IRUSR | S_IWUSR);
		else if (redirections[i][0] == 'p')
		{
			str = ft_strdup("");
			while (42)
			{
				// printf ("in the loop 42\n");
				buff = readline("dquotes<");
				// printf("buuf -- %s\n", buff);
				if (ft_strlen(targets[i]) == ft_strlen(buff))
					if (!ft_strncmp(targets[i], buff, BUFFER_SIZE))
						break;
				str = ft_join_free(str,ft_join_free(buff, "\n", 1), 3);
			}
		} 
		else if (redirections[i][0] == '>')
			stdout = open(targets[i],O_CREAT | O_WRONLY |  O_TRUNC, S_IRUSR | S_IWUSR);
		else
			stdin = open(targets[i],O_RDONLY, S_IRUSR | S_IWUSR);
		_fct(todo, env, stdin, stdout, str);
		if (stdin > 2)
			close(stdin);
		if (stdout > 2)
			close(stdout);
		stdout = 1;
		stdin = 0;
		// printf ("in the end redir\n");
	}
    return (1);
}