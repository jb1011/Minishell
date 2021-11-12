/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting&ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/08/30 21:47:51 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_dup(const char *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == 0)
		{
			break ;
		}
		while (s[i] == c)
			i++;
		str[j] = (char)s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	is_redir(char s)
{
	if (s == '>' || s == '<')
		return (1);
	return (0);
}

char	**mall_doubletab(char **t)
{
	int		j;
	char	**new;

	j = 0;
	new = NULL;
	if (t[0] == 0)
		return (0);
	while (t[j])
		j++;
	new = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (t[j])
	{
		new[j] = ft_strtrim(t[j], " ");
		j++;
	}
	new[j] = 0;
	return (new);
}

int	is_redir_str(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			count++;
		if ((s[i] == '>' || s[i] == '<') && (count % 2 == 0))
			return (1);
		i++;
	}
	return (0);
}
