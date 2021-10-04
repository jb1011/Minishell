/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/04 15:56:58 by lgelinet         ###   ########.fr       */
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

char *set_prompt(void)
{
    char buffer[BUFFER_SIZE + 1];
    char *prompt;

    getcwd(buffer, BUFFER_SIZE);
    prompt = ft_strjoin("\033[0;35m", buffer);
    prompt = ft_join_free(prompt, " \033[0;34m", 1);
    prompt = ft_join_free(prompt, SHELL_PROMPT, 1);
    prompt = ft_join_free(prompt, " \033[0;0m", 1);
    return (prompt);
}
int     begin(t_all *all)
{
    int i;
    char *str;
    char *prompt;

    i = -1;
    ft_bzero(all->path, BUFFER_SIZE);
    getcwd(all->path, BUFFER_SIZE - 1);
    prompt = set_prompt();
    all->line = readline(prompt);
    free (prompt);
    if (!all->line)
        all->line = ft_strdup("exit");
	add_history(all->line);
    // printf("%s\n", all->line);
    return (1);
}
