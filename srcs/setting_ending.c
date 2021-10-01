/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/01 17:41:15 by lgelinet         ###   ########.fr       */
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
    // printf("%s\n%sifhjweuifhweuifhwefuh\n", all->env->var, all->env->val);
    return(1);
}

int     put_prompt(char *path)
{
    char buffer[BUFFER_SIZE + 1];

    ft_putstr("\033[0;35m");
    getcwd(buffer, BUFFER_SIZE);
    ft_putstr(buffer);
    ft_putstr(" \033[0;34m");
    ft_putstr(SHELL_PROMPT);
    ft_putstr(" \033[0;0m");
    return (1);
}
int     begin(t_all *all)
{
    int i;
    char *str;

    i = -1;
    ft_bzero(all->path, BUFFER_SIZE);
    getcwd(all->path, BUFFER_SIZE - 1);
    put_prompt(all->path);
    all->line = readline("");
    if (!all->line)
        all->line = ft_strdup("exit");
	add_history(all->line);
    // printf("%s\n", all->line);
    return (1);
}
