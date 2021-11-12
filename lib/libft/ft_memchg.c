/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:48:56 by lgelinet          #+#    #+#             */
/*   Updated: 2020/11/30 11:13:16 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	int				i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (pdst[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		++i;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	unsigned int		i;
	unsigned char		*ptr1;
	unsigned char		*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	signed char	operation;
	int			end;
	int			current;

	if (dest != src)
	{
		if (dest < src)
		{
			operation = 1;
			current = 0;
			end = n;
		}
		else
		{
			operation = -1;
			current = n - 1;
			end = -1;
		}
		while (current != end)
		{
			*(((char *)dest) + current) = *(((char *)src) + current);
			current += operation;
		}
	}
	return (dest);
}
