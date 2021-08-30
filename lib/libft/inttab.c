/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:17:25 by lgelinet          #+#    #+#             */
/*   Updated: 2021/06/24 16:18:05 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	xtrms(int *tab, int size, char what)
{
	int	i;
	int	ret;

	i = -1;
	if (what == '<')
	{
		ret = 2147483647;
		while (++i < size)
			if (ret > tab[i])
				ret = tab[i];
		return (ret);
	}
	ret = -2147483648;
	while (++i < size)
		if (ret < tab[i])
			ret = tab[i];
	return (ret);
}

int	checkorder(int *a, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (a[i - 1] > a[i])
			return (0);
	return (1);
}
