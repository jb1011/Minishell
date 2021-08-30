/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:31:56 by lgelinet          #+#    #+#             */
/*   Updated: 2021/06/24 15:48:55 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_error(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static unsigned int	ft_cntstr(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cnt;

	if (!s[0])
		return (0);
	i = 0;
	cnt = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		cnt++;
	return (cnt);
}

static void	ft_get_next_str(char **next_str, unsigned int *sizestr, char c)
{
	unsigned int	i;

	*next_str += *sizestr;
	*sizestr = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*sizestr)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	char			*next_str;
	unsigned int	sizestr;
	unsigned int	cnt;
	unsigned int	i;

	if (!s)
		return (NULL);
	cnt = ft_cntstr(s, c);
	i = 0;
	next_str = (char *)s;
	sizestr = 0;
	while (i < cnt)
	{
		ft_get_next_str(&next_str, &sizestr, c);
		strs[i] = malloc(sizeof(char) * (sizestr + 1));
		if (!strs[i])
			return (ft_free_error(strs));
		ft_strlcpy(strs[i], next_str, sizestr + 1);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
