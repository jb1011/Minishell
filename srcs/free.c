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

void	ft_free_tab(char **t)
{
	int j;

	j = 0;
	while (t[j])
	{
		free(t[j]);
		j++;
	}
	free(t);
}

void	ft_free_megatab(char ***t)
{
	int j;

	j = 0;
	while (t[j])
	{
		ft_free_tab(t[j]);
		j++;
	}
	free(t);
}
