/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:59:20 by lgelinet          #+#    #+#             */
/*   Updated: 2021/06/24 17:11:37 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	t_slv	s;

	s = (t_slv){0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (!ft_isdigit(str[s.i]))
		s.i++;
	while (ft_isdigit(str[s.i]))
		s.i++;
	if (str[s.i] == '.')
	{
		s.da = s.i + 1;
		while (ft_isdigit(str[++s.i]))
			s.j++;
		s.da = ((double)ft_atoi(&str[(int)s.da]) / (double)ft_pow(10, s.j));
	}
	s.k = ft_atoi(str);
	if (s.k < 0)
		s.i = -1;
	else
		s.i = 1;
	return (s.i * (s.i * s.k + s.da));
}

int	ft_abs(int to_abs)
{
	return (ft_sqrt(to_abs * to_abs));
}

int	ft_atoi(char *str)
{
	t_slv	s;

	s = (t_slv){0, 0, 1, 0, 0, 0, 0, 0};
	while (ft_iswhitespace(str[s.i]))
		s.i++;
	if (str[s.i] == '-')
		s.k *= -1;
	else
		s.i--;
	while (ft_isdigit(str[++s.i]))
		s.la = s.la * 10 + (str[s.i] - '0');
	s.la *= s.k;
	if (s.la > 2147483647 || s.la < -2147483648)
		return (0);
	return ((int)s.la);
}

int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 && n > -2147483648)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	char			*str;
	int				i;
	int				size;
	unsigned int	temp;
	int				n;

	n = (int)nb;
	size = ft_itoa_size(n);
	i = 1;
	str = malloc(size + 1);
	str[size] = '\0';
	temp = ft_abs(n);
	if (temp == 0)
		str[0] = '0';
	while (temp >= 1)
	{
		str[size - i] = (temp % 10) + '0';
		temp /= 10;
		i++;
	}
	if (n < 0)
		*str = '-';
	return (str);
}
