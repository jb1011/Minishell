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
	int	j;

	j = 0;
	while (t[j])
	{
		printf("\t%s\n", t[j]);
		j++;
	}
}

void	ft_print_megatab(char ***t)
{
	int	j;
	int	i;

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
	int	i;

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
