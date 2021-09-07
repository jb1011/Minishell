/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/02 13:17:28 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	db_quote_open(char *str, int end)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(i < end)
	{
		if (str[i] == '"')
			count ++;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}

void	trim_quote(char ***t)
{
	int	i;
	int	j;
	char	*tmp;

	j = 0;
	while (t[j])
	{
		i = 0;
		while (t[j][i])
		{
			if (t[j][i][0] == '"')
			{
				tmp = ft_strtrim(t[j][i], "\"");
				free(t[j][i]);
				t[j][i] = ft_strdup(tmp);
				free(tmp);
			}
			if (t[j][i][0] == '\'')
			{
				tmp = ft_strtrim(t[j][i], "\'");
				free(t[j][i]);
				t[j][i] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
}

char	*delete_quote_nospace(char *str)
{
	char	*tmp;
	int	i;
	int	flag;
	int	quote;

	flag = 0;
	if (ft_strchr(str, '\'') || ft_strchr(str, '"'))
		flag = 1;
	i = 0;
	if (flag)
	{
		while (str[i])
		{
			if (str[i] == '\'')
				quote = 1;
			if (str[i] == '"')
				quote = 2;
			i++;
		}
		i = 0;
		if (quote == 1)
			tmp = ft_dup(str, '\'');
		if (quote == 2)
			tmp = ft_dup(str, '"');
		str = ft_strdup(tmp);
		free(tmp);
	}
	return (str);
}

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
			ft_putstr("!!!!!");
			break ;
		}
		if (s[i] == c)
			i++;
		str[j] = (char)s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	ft_putstr("ligne : ");
	ft_putstr(str);
	ft_putstr("\n");

	return (str);
}