/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:25 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/14 16:06:36 by lgelinet         ###   ########.fr       */
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

int     do_builtins(t_all *all, char **opts)
{
    if (!ft_strncmp(*opts, "cd", ft_strlen(*opts)))
        return (_cd(opts[1]));
    if (!ft_strncmp(*opts, "export", ft_strlen(*opts)))
        return (_export(all, opts));
    if (!ft_strncmp(*opts, "unset", ft_strlen(*opts)))
        return (_unset(&all->env, opts));
    if (!ft_strncmp(*opts, "exit", ft_strlen(*opts)))
        return (1);
    if (!ft_strncmp(*opts, "/usr/bin/echo", ft_strlen(*opts)))
        return(_echo(all, opts));
    if (!ft_strncmp(*opts, "echo", ft_strlen(*opts)))
        return(_echo(all, opts));
    if (!ft_strncmp(*opts, "/usr/bin/pwd", ft_strlen(*opts)))
        return(_pwd(all));
    if (!ft_strncmp(*opts, "pwd", ft_strlen(*opts)))
        return(_pwd(all));
    if (!ft_strncmp(*opts, "/usr/bin/env", ft_strlen(*opts)))
        return (_env(all, opts));
    if (!ft_strncmp(*opts, "env", ft_strlen(*opts)))
        return (_env(all, opts));
    // printf("not a builtins\n");
    return (0);
}


int     isfct(char **path, char **fct)
{
    int fd;
    int i;
    char *buff;

    i = 0;
    if (assign(&fd, open(*fct, O_RDONLY)) != -1)
    {
        close(fd);
        return (1);
    }
    buff = ft_join_free(ft_strjoin(path[0], "/"), *fct, 1);
    while (assign(&fd, open(buff, O_RDONLY)) < 1 && path[++i])
    {
        free(buff);
        buff = ft_join_free(ft_strjoin(path[i], "/"), *fct, 1);
    }
    free (buff);
    if (!path[i])
        return (0);
    close(fd);
    *fct = ft_join_free(ft_strjoin(path[i], "/"), *fct, 3);
    return (1);
}

int     treat_orders(t_all *all, t_pipenodes *node)
{
    char *msg;
    int i;
    
    i = -1;
    if (!node || !(node->orders))
        return  (0);
    while(node->orders[++i])
        changeline(all, &node->orders[i]);
    i = -1;
    while (node->orders[++i] && ft_strchr(node->orders[i], '='))
        ;
    if (!node->orders[i])
    {
        i = -1;
        while (node->orders[++i])
            assign_var(all, node->orders[i], 0);
        return (1);  
    }
    //printf("lool%s\n", *node->orders);
    if (do_builtins(all, node->orders))
        return (1);
    if (isfct(all->exec_paths, node->orders))
        return (redirect_fcts(node->redir, node->targets, node->orders, env_to_strtab(all->env)));
    msg = ft_strjoin("minishell : command not found: ",*node->orders);
    ft_err_msg(msg);
    free (msg);
    return (-1);
}
