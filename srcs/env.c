/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:39:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/03 16:23:03 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

int     advar(t_env **list, char *var, char *val)
{
    t_slv s;
    t_env *ret;

    ret = malloc(sizeof(t_env));
    ret->var = ft_strdup(var);
    ret->val = ft_strdup(val);
    ret->nxt = *list;
    *list = ret;
    return (1);
}

t_env     *vardo(t_env *list, char *tofind, char *ch_val, char del)
{
    t_env *ret;
    t_env   *temp;

    ret = list;
    if (!list)
        return (NULL);
    while (ret && ft_strncmp(ret->var, tofind, ft_strlen(ret->var)))
    {
        temp = ret;
        ret = ret->nxt;
    }
    if (ch_val && ret)
    {
        free(ret->val);
        ret->val = ft_strdup(ch_val);
    }
    if (!del)
        return (ret);
    temp->nxt = ret->nxt;
    free(ret->var);
    free(ret->val);
    free(ret);
    return (NULL);
}

int         printenv(t_env *env)
{
    printf("%s=%s\n", env->var, env->val);
}
