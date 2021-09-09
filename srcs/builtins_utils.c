/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:55 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/09 15:21:17 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int     do_builtins(t_all *all, char **opts)
{
    if (!ft_strncmp(*opts, "cd", ft_strlen(*opts)))
        return (_cd(opts[1]));
    if (!ft_strncmp(*opts, "export", ft_strlen(*opts)))
        return (_pwd(all));
    if (!ft_strncmp(*opts, "unset", ft_strlen(*opts)))
        return (_pwd(all));
    if (!ft_strncmp(*opts, "exit", ft_strlen(*opts)))
        return (1);
    if (!ft_strncmp(*opts, "/usr/bin/echo", ft_strlen(*opts)))
        return(_echo(all, opts, 0, 0));
    if (!ft_strncmp(*opts, "echo", ft_strlen(*opts)))
        return(_echo(all, opts, 0, 0));
    if (!ft_strncmp(*opts, "/usr/bin/pwd", ft_strlen(*opts)))
        return(_pwd(all));
    if (!ft_strncmp(*opts, "pwd", ft_strlen(*opts)))
        return(_pwd(all));
    if (!ft_strncmp(*opts, "/usr/bin/env", ft_strlen(*opts)))
        return (_env(all, opts, 0, 0));
    if (!ft_strncmp(*opts, "env", ft_strlen(*opts)))
        return (_env(all, opts, 0, 0));
    return (0);
}

int     treat_orders(t_all *all, char **opts)
{
    char *msg;
    if (do_builtins(all, opts))
        return (1);
    if (isfct(all->exec_paths, opts))
        return (_fct(opts, env_to_strtab(all->env)));
    msg = ft_strjoin("minishell : command not found: ",*opts);
    ft_err_msg(msg);
    free (msg);
    return (-1);
}