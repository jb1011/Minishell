/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:47:27 by lgelinet          #+#    #+#             */
/*   Updated: 2021/01/08 12:16:49 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	char	*pdest;
	char	*psrc;
	int		len;
	int		dst_len;

	pdest = (char *)ft_memchr(dst, '\0', size);
	if (!pdest)
		return (size + ft_strlen(src));
	psrc = (char *)src;
	pdest = (char *)dst;
	dst_len = ft_strlen(dst);
	len = dst_len + ft_strlen(psrc);
	pdest += dst_len;
	while (dst_len++ < size - 1 && *psrc)
		*pdest++ = *psrc++;
	*pdest = '\0';
	return (len);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < size)
		ft_memcpy(dst, src, (srclen + 1));
	else if (size != 0)
	{
		ft_memcpy(dst, src, (size - 1));
		dst[size - 1] = '\0';
	}
	return (srclen);
}

int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *subs, int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (subs[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == subs[j])
		{
			while (i + j < len && big[i + j] == subs[j])
			{
				j++;
				if (!subs[j])
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n && (ptr1[i] != '\0' || ptr2[i] != '\0'))
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}
