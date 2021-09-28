/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:11:42 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/27 15:06:32 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     do_pipes(t_all *all, t_env *env, t_pipenodes *nd)
{
    int id;
    int fd[2];
    int real_in;
    
    if (all->count_list == 1 || !nd->next)
        return (treat_orders(all, nd));
    pipe(fd);
    if (!fork())
    {
        close(fd[0]);
        dup2(fd[1], 1);
        do_pipes(all, env, nd->next);
        close(fd[1]);
        close (1);
        exit(1);
    }
    close (fd[1]);
    waitpid(id, 0 , 0);
    real_in = dup(0);
    dup2(fd[0],0);
    treat_orders(all, nd);
    close(fd[0]);
    dup2(real_in,0);
    return (1);
}