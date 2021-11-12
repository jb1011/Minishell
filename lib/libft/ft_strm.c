/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:44:15 by lgelinet          #+#    #+#             */
/*   Updated: 2021/02/18 15:09:37 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(void *s)
{
	char			*ptr;
	char			*dup;
	unsigned int	i;

	i = 0;
	if (!s)
		return (ft_strdup("(null)"));
	ptr = (char *)s;
	dup = (char *)malloc(sizeof(char) * ft_strlen(ptr) + 1);
	if (dup == NULL)
		return (NULL);
	while (i < ft_strlen(ptr))
	{
		dup[i] = ptr[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 && s2[i])
	{
		str[j + i] = s2[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	size;
	char			*start;
	char			*end;
	char			*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	if (i != -1)
		while (i >= 0 && ft_strchr(set, s1[i]))
			i--;
	end = (char *)&s1[i];
	if (!*s1 || end == start)
		size = 2;
	else
		size = end - start + 2;
	str = malloc(sizeof(char) * size);
	ft_strlcpy(str, start, size);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		substr = malloc(sizeof(char) * 1);
		substr[0] = '\0';
		return (substr);
	}
	substr = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_join_free(char *s1, char *s2, int freed)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (freed == 3 || freed == 1)
		do_free(s1);
	if (freed == 3 || freed == 2)
		do_free(s2);
	return (ret);
}
