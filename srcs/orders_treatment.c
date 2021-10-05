/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:25 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 13:15:36 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int changeline(t_all *all, char **line)
{
    t_slv s;

    s = (t_slv){-1, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
    while ((*line)[++s.i])
    {        
        if ((*line)[s.i] == '\"' && !s.j)
            quotes_bool(&s.k);
        else if ((*line)[s.i] == '\'' && !s.k) 
            quotes_bool(&s.j);
        else if (s.j) // s.j --->> apostrophe !!!!!!
            str_case(&s.stra, (*line), &s.i, STOP_QUOTE);
        else if ((*line)[s.i] == '$')
            dollar_case(&s.stra, (*line), &s.i, all);
        else if (s.k) // s.k -->>> GUILLEMETS
            str_case(&s.stra, (*line), &s.i, STOP_DBLQUOTE);
        else
            str_case(&s.stra, (*line), &s.i, STOP_STR);
    }
    free(*line);
    *line = s.stra;
    return (1);
}

int     is_builtins(char **opts)
{
    int len;

    if (assign(&len, ft_rankchr(*opts, '=')))
        if (opts[0][len])
            return (6);
    len = ft_strlen(*opts) + 1;
    if (len > 7)
        return (0);
    if (len == 7)
        if (!ft_strncmp(*opts, "export", 7))
            return (1);
    if (len == 6)
        if (!ft_strncmp(*opts, "unset", 6))
            return (2);
    if (len == 5)
        if (!ft_strncmp(*opts, "echo", 5))
            return(3);
    if (len ==4)
    {
        if (!ft_strncmp(*opts, "pwd", 4))
            return(4);
        if (!ft_strncmp(*opts, "env", 4))
            return (5);
    }
    return (0);
}
int     do_builtins(t_all *all, char **opts, int no_builtins)
{
    if (!no_builtins)
        return (0);
    if (no_builtins == 1)
        return (_export(all, opts));
    if (no_builtins == 2)
        return (_unset(&all->env, opts));
    if (no_builtins == 3)
        return(_echo(all, opts));
    if (no_builtins == 4)
        return(_pwd(all));
    if (no_builtins == 5)
        return(_env(all, opts));
    if (no_builtins == 6)
    {
        if (all->count_list == 1)
            return(assign_var(all, *opts, 0));
        else
            return (write(1, "\0", 1));
    }
    return (0);
}


int     isfct(char **path, char **fct)
{
    int fd;
    int i;
    char *buff;

    i = 0;
    buff = ft_join_free(ft_strjoin(path[0], "/"), *fct, 1);
    while (assign(&fd, open(buff, O_RDONLY)) < 1 && path[++i])
    {
        free(buff);
        buff = ft_join_free(ft_strjoin(path[i], "/"), *fct, 1);
        close (fd);
    }
    free (buff);
    if (!path[i])
    {
        status = 127;
        printf("%s : command not found\n", *fct);
        return (0);
    }
    close(fd);
    *fct = ft_join_free(ft_strjoin(path[i], "/"), *fct, 3);
    return (1);
}


int     treat_orders(t_all *all, t_pipenodes *node)
{
    int i;
    int len;
    char **env;
    
    i = -1;
    if (!node || !(node->orders))
        return  (0);
    while (node->orders[++i])
      changeline(all, &node->orders[i]);
    len = ft_strlen(node->orders[0]);
    if (len == 4 && !ft_strncmp("exit", node->orders[0], 4))
        return (_myexit(all));
    i = -1;
    if (len == 2 && !ft_strncmp(node->orders[0], "cd", len))
        return (_cd(node->orders[1]));
    env = env_to_strtab(all->env);
    redirect_fcts(all, node->redir, node->targets, node->orders, env);
    free_doubletab(env);
    return (1);
}
