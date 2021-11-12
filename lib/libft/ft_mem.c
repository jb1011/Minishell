/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:54:09 by lgelinet          #+#    #+#             */
/*   Updated: 2020/12/01 17:48:33 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	ft_bzero(ptr, size * count);
	return (ptr);
}

int	do_free(void *freed)
{
	if (freed)
	{
		free(freed);
		freed = NULL;
		return (1);
	}
	return (0);
}

char	*chartostr(char c)
{
	char	s[2];

	*s = c;
	s[1] = 0;
	return (ft_strdup(s));
}

int	free_doubletab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return (0);
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
	return (1);
}
