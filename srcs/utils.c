/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting&ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/08/30 21:47:51 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_tab(char **t)
{
	int j;

	j = 0;
	printf("**TAB :\n");
	while (t[j])
	{
		printf("%s\n", t[j]);
		j++;
	}
}

void	ft_print_megatab(char ***t)
{
	int j;
	int i;

	j = 0;
	printf("***TAB :\n");
	while (t[j])
	{
		i = 0;
    	printf("\tCASE %d :\n", j);
		while (t[j][i])
		{
        	printf("\t\tCASE STRING :\n");
			printf("\t\t\t%s\n", t[j][i]);
			i++;
		}
		j++;
	}
}
