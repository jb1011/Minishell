/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:38:31 by lgelinet          #+#    #+#             */
/*   Updated: 2021/02/25 13:38:55 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rankchr(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i + 1);
	return (0);
}

void	*ft_memchr(const void *s, int c, int n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (n--)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i++;
	}
	if (c == '\0')
		return (&ptr[i]);
	return (NULL);
}

int	pure_set(char *set, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_strchr(set, str[i]))
			return (0);
	return (1);
}

int	argvsrch(char **tab, char find)
{
	int	i;
	int	j;
	int	s;

	i = -1;
	s = 0;
	while (tab[++i] && assign(&j, -1) == -1)
		while (tab[i][++j])
			if (tab[i][j] == find)
				s++;
	return (s);
}
