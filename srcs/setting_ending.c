/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/12 22:42:26 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

int	init(t_all *all, char *where_is_shell)
{
	getcwd(all->path, BUFFER_SIZE);
	chdir(all->path);
	all->env = NULL;
	all->minishell = ft_strjoin(all->path, &where_is_shell[1]);
	advar(&all->env, "PATH", getenv("PATH"), EXPORT);
	all->exec_paths = ft_split(all->env->val, ':');
	advar(&all->env, "USER", getenv("USER"), EXPORT);
	advar(&all->env, "SHELL", "minishell", EXPORT);
	advar(&all->env, "DESKTOP_SESSION", getenv("DESKTOP_SESSION"), EXPORT);
	return (1);
}

char	*set_prompt(void)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*prompt;

	ft_bzero(buffer, BUFFER_SIZE);
	getcwd(buffer, BUFFER_SIZE);
	prompt = ft_strjoin("\033[0;35m", buffer);
	prompt = ft_join_free(prompt, " \033[0;34m", 1);
	prompt = ft_join_free(prompt, SHELL_PROMPT, 1);
	prompt = ft_join_free(prompt, " \033[0;0m", 1);
	return (prompt);
}

int	begin(t_all *all)
{
	char		*prompt;
	t_winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	w.ws_col = -1;
	ioctl(0, TIOCSWINSZ, &w);
	ft_bzero(all->path, BUFFER_SIZE);
	getcwd(all->path, BUFFER_SIZE - 1);
	prompt = set_prompt();
	all->line = readline(prompt);
	free(prompt);
	if (!all->line)
		all->line = ft_strdup("exit");
	else
		add_history(all->line);
	return (1);
}
