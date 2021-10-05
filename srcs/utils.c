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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(char **t)
{
	int j;

	j = 0;
	while (t[j])
	{
		printf("\t%s\n", t[j]);
		j++;
	}
}

void	ft_print_megatab(char ***t)
{
	int j;
	int i;

	j = 0;
	printf("***TAB :\n");
	while (t[j])
	{
		i = 0;
    	printf("\tCASE %d :\n", j);
		while (t[j][i])
		{
        	printf("\t\tCASE STRING :\n");
			printf("\t\t\t%s\n", t[j][i]);
			i++;
		}
		j++;
	}
}

char	*ft_dup_char(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			count++;
		if ((s[i] == '|' || s[i] == '<' || s[i] == '>') && (count % 2 != 0))
			i++;
		str[j] = (char)s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	ft_malloc_tab(char ***t, int size, char **s)
{
	int i;

	i = 0;
	while (i < size)
	{
		t[i] = (char **)malloc(sizeof(char *) * 2);
		i++;
	}
	i = 0;
	while (s[i])
	{
		t[i][0] = ft_strdup(s[i]);
		t[i][1] = 0;
		i++;
	}
	t[i] = 0;
}

int	ft_get_nb_strs(char *s, char c)
{
	int	i;
	int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

int	is_separator(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '>' || s[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

int	is_char_separator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	quote_is_odd(char *s, int end)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(i < end)
	{
		if (s[i] == '\'')
			count ++;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}

void	megatab_malloc_simple(t_all *all)
{
	all->w_line = malloc(sizeof(char **) * 2);
	all->w_line[0] = (char **)malloc(sizeof(char *) * 2);
	all->w_line[0][0] = ft_strdup(all->line);
	all->w_line[0][1] = 0;
	all->w_line[1] = 0;
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

char **mall_doubletab(char **t)
{
	int	j;
	char **new;

	j = 0;
	new = NULL;
	if (t[0] == 0)
		return (0);
	while(t[j])
		j++;
	new = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (t[j])
	{
		// new[j] = ft_strdup(t[j]);
		new[j] = ft_strtrim(t[j], " ");
		j++;
	}
	new[j] = 0;
	return (new);
}

int	is_redir_str(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '>' || s[i] == '<')
			return (1);
		i++;
	}
	return (0);
}