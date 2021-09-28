/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/10 16:52:30 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>


int     init(t_all *all)
{
    ft_strlcpy(all->path, "/home/",7);
	ft_strlcat(all->path, getenv("USER"), BUFFER_SIZE - 7);
	chdir(all->path);
    all->env = NULL;
    advar(&all->env, "PATH", getenv("PATH"), EXPORT);
    all->exec_paths = ft_split(all->env->val, ':');
    advar(&all->env, "USER", getenv("USER"), EXPORT);
    advar(&all->env, "SHELL", "minishell", EXPORT);
    advar(&all->env, "DESKTOP_SESSION", getenv("DESKTOP_SESSION"), EXPORT);
}

int     begin(t_all *all)
{
    ft_bzero(all->path, BUFFER_SIZE);
    getcwd(all->path, BUFFER_SIZE - 1);
    printf("\033[0;35m%s \033[0;34m%s \033[0;0m", all->path, SHELL_PROMPT);
    all->line = readline("-> ");
	add_history(all->line);
    return (1);
}
