/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:11:42 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/23 17:16:00 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     treatall(t_all *all, t_env *env, t_pipenodes *nd)
{
    if (!nd->next)
        redirect_fcts(all, nd->redir, nd->targets, nd->orders, env_to_strtab(env));
}