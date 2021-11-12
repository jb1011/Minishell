/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:41:45 by lgelinet          #+#    #+#             */
/*   Updated: 2021/06/24 15:43:10 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int nb, int power)
{
	int	i;

	i = nb;
	if (power == 0)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	while (power > 1)
	{
		nb *= i;
		power--;
	}
	return (nb);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb > (46340 * 46340))
		return (0);
	while (i <= 46340 && i <= (nb / 2))
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	near(double nb)
{
	if ((double)(nb - (int)nb) > 0.5)
		return ((int)(nb + 1));
	return ((int)nb);
}
