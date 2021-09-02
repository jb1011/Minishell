/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:53:18 by lgelinet          #+#    #+#             */
/*   Updated: 2020/11/30 14:30:23 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, int n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_doubletabintset(int **tab, int lenght, int withd)
{
	int	i;
	int	j;

	i = -1;
	tab = (int **)malloc(sizeof(int *) * (lenght));
	while (++i < lenght)
	{
		tab[i] = malloc(sizeof(int) * withd);
		j = -1;
		while (++j < withd)
			tab[i][j] = 0;
	}
	return (0);
}

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

char	*extractstr(char *str, char *set_to_stop)
{
	int	i;
	int	j;
	char *ret;

	i = 0;
	if (!set_to_stop || !*str)
		return(ft_strdup(""));
	while(str[i] && !ft_strchr(set_to_stop, str[i]))
		i++;
	if (!str[i])
		return (ft_strdup(str));
	ret = malloc(i * sizeof(char) + 1);
	j = -1;
	while (++j < i)
		ret[j] = str[j];
	ret[i] = 0;
	return (ret);
}