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

void	ft_print_tab(char **tab)
{
	int j;

	j = 0;
	printf("**TAB :\n");
	while (tab[j])
	{
		printf("%s\n", tab[j]);
		j++;
	}
}

void	ft_print_megatab(char ***tab)
{
	int j;
	int i;

	j = 0;
	printf("***TAB :\n");
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			printf("%s\n", tab[j][i]);
			i++;
		}
		j++;
	}
}
