/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/09 22:01:06 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

int     begin(t_all *all)
{
    getcwd(all->path, 400);
    printf("%s %s", all->path, SHELL_PROMPT);
    all->line = readline("-> ");
	add_history(all->line);
    printf("%s\n", all->line);
    return (1);
}

int     init(t_all *all)
{
    ft_strlcpy(all->path, "/home/",7);
	ft_strlcat(all->path, getenv("USER"), 393);
	chdir(all->path);
    all->env = NULL;
    advar(&all->env, "PATH", getenv("PATH"), EXPORT);
    all->exec_paths = ft_split(all->env->val, ':');
    advar(&all->env, "USER", getenv("USER"), EXPORT);
    advar(&all->env, "SHELL", "minishell", EXPORT);
    advar(&all->env, "DESKTOP_SESSION", getenv("DESKTOP_SESSION"), EXPORT);
}