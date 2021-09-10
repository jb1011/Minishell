/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:55 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/10 13:50:45 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     _env(t_all *all,char **opts)
{
    t_env   *ptr;
    t_slv   s;

    if (opts[1])
        return (ft_err_msg("Env treated alone"));
    else
        s.k = 0;;
    ptr = all->env;
    s.stra = ft_strdup("");
    while (ptr)
    {
        if (s.k && ptr->is_env)
            printenv(ptr);
        else if (ptr->is_env)
            printf("af faire plus tard\n");
        ptr = ptr->nxt;
    }
    return (1);
}

int     _export(t_all *all, char **opts)
{
    int i;

    i = 0;
    while (opts[++i])
        assign_var(all, opts[i], EXPORT);
}

int     _unset(t_env **list, char **opts)
{
    int i;
    i = 0;
    while (opts[++i])
        vardo(list, opts[i], 0, UNSET);
    return (1);
}
