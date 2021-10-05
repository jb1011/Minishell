/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:54:53 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 13:32:17 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int treatall(t_all *all, t_env *env, t_pipenodes *node)
{
    if (!node)
        return (0);
    piping(all, env, node);
    return (1);
}