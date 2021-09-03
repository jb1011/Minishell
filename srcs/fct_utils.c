/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 00:56:20 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/03 15:48:14 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int dollar_case(char **buffer, char *object, int *index)
{
    int k;
    char    *temp;
    
     if (object[*index + 1] == '$' && ++*index)
        *buffer = ft_join_free(*buffer, ft_itoa(getpid()), 3);
    else if (!object[*index + 1])
        *buffer = ft_join_free(*buffer, "$", 1);
    else
    {
        k = *index + 1;
        while (!ft_strchr(STOP_DOLLAR, object[++*index]))
            ;
        temp = extractstr(&object[k], STOP_DOLLAR);
        *buffer = ft_join_free(*buffer, getenv(temp), 1);
        free(temp);
        --*index;
        return (0);
    }
    return (1);
}

int str_case(char **buffer, char *object, int *index, char *stops)
{
    int k;
    char *temp;

    k = *index;
    // if (!ft_memcmp(STOP_QUOTE, stops, 4))
    //     k++;
    while (!ft_strchr(stops, object[++*index]))
        ;
    temp = extractstr(&object[k], stops);
    *buffer = ft_join_free(*buffer, temp,  3);
    --*index;
    if (object[*index + 1])
        return (1);
    return (0);
}

void quotes_bool(int *boolean)
{
    if (!*boolean)
        ++*boolean;
    else
        *boolean = 0;
}

