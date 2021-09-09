/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:39:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/09 14:56:36 by lgelinet         ###   ########.fr       */
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

t_env     *vardo(t_env **list, char *tofind, char *ch_val, char del)
{
    t_env *ret;
    t_env   *temp;

    temp = NULL;
    ret = *list;
    if (!*list)
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
    
    if (ret)
    {
        if (!temp)
            *list = ret->nxt;
        else
            temp->nxt = ret->nxt;
        free(ret->var);
        free(ret->val);
        free(ret);
    }
    return (NULL);
}

int         printenv(t_env *env)
{
    printf("%s=%s\n", env->var, env->val);
}

char    **env_to_strtab(t_env *list)
{
    t_env *ptr;
    int     i;
    char    **ret;

    i = 0;
    if (!list)
        return (0);
    ptr = list;
    while (ptr && ++i)
        ptr = ptr->nxt;
    ret = malloc(sizeof(char *) * (i + 1));
    ret[i] = NULL;
    ptr = list;
    i = -1;
    while (ret[++i])
    {
        ret[i] = ft_strjoin(ft_strjoin(ptr->var, "="), ptr->val);
        ptr = ptr->nxt;
    }
    return (ret);

}