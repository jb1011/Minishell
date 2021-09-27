/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:11:42 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/27 14:49:34 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     treatall(t_all *all, t_env *env, t_pipenodes *nd)
{
    int id;
    int fd[2];
    int real_in;
    
    if (all->count_list == 1)
        return (treat_orders(all, nd));
    if (!nd->next)
        return (treat_orders(all, nd));
    pipe(fd);
    id = fork();
    if (!id)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        execve(*nd->next->orders, nd->next->orders, 0);
        // treat_orders(all, nd->next);
        treatall(all, env, nd->next);
        // write(1, "LIL\nLOL\nLEL\n", 13);
        close(fd[1]);
        close (1);
        exit(1);
    }
    else// if (waitpid(id, 0 , 0) != -2)
    {
        close (fd[1]);
        real_in = dup(0);
        dup2(fd[0],0);
        // close(fd[0]);
        // // execve(*nd->next->orders, nd->next->orders, 0);
        // redirect_fcts(all, nd->redir, nd->targets, nd->orders, env);
        treat_orders(all, nd);
        printf("c'est dans le parent\n");
    }
    dup2(real_in,0);
    return (1);
}