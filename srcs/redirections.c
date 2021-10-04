/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:00:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/04 15:11:28 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <fcntl.h>
#include <readline/readline.h>


int		redirect_fcts(t_all *all, char **redirections, char **targets, char *todo[], char *env[])
{
	int	i;
	int stdout;
	int stdin;
	char	*buff;
	int		size;
	int		fd[2];
	char	buff2[BUFFER_SIZE + 1];
	int		right_redirect = 0;

	i = -1;
	stdin = 0;
	if (!redirections)
		return (_fct(all, todo, env, 0, 1));
	pipe(fd);
	while (targets[++i])
	{
		if (redirections[i][0] == 'p')
		{
			while (42)
			{
				buff = readline("dquotes<");
				if (ft_strlen(targets[i]) == ft_strlen(buff))
					if (!ft_strncmp(targets[i], buff, ft_strlen(targets[i])) && do_free(buff))
						break;
				buff = ft_join_free(buff, "\n", 1);
				write(fd[1], buff, ft_strlen(buff));
				free(buff);
			}
		}
		else if (redirections[i][0] == '<')
		{
			stdin = open(targets[i],O_RDONLY, S_IRUSR | S_IWUSR);
			while (assign(&size, read(stdin , buff2, BUFFER_SIZE)) > 0)
			{
				buff2[size] = 0;
				write(fd[1], buff2, size - 1);
			}
			close(stdin);
		}
	}
	close(fd[1]);
	i = -1;
	while (targets[++i])
	{
		if (redirections[i][0] == 'g' && ++right_redirect)
			_fct(all, todo, env, fd[0], open(targets[i],O_CREAT | O_WRONLY |  O_APPEND, S_IRUSR | S_IWUSR));
		else if (redirections[i][0] == '>' && ++right_redirect)
			_fct(all, todo, env, fd[0], open(targets[i],O_CREAT | O_WRONLY |  O_TRUNC, S_IRUSR | S_IWUSR));
	}
	if (!right_redirect)
		_fct(all, todo, env, fd[0], 1);
	close(fd[0]);
    return (1);
}