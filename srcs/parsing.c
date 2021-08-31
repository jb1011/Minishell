#include "../includes/minishell.h"


void    it()
{
	return;
}

int    parse_line(t_all *all)
{
	// all->splt_line = ft_split(all->line, ";| >");
	// ft_print_tab(all->splt_line);

	// int i;
	// char *iso;
	// char *rest;

	// i = 0;
	// rest = ft_strdup(all->line);
	// while (rest[i])
	// {
	// 	if (ft_strchr(";|> ", all->line[i]))
	// 	{
	// 		iso = ft_substr(all->line, 0, i);
	// 		rest = ft_strdup(&str[i]);
	// 	}
	// 	i++;
	// }

	// printf("%d", ft_count_split(all->line));

	// while (all->w_line[i])
	// {
	// 	all->w_line[i] = ft_split(all->splt_line[i], '|');
	// 	i++;
	// }
	// all->w_line[i] = 0;

	all->w_line = malloc(sizeof(char **) * ft_count_split(all->line) + 1);

	all->splt_line = ft_split(all->line, ';');
	int j = 0;
	if (ft_strchr(all->line, '|'))
	{
		while (all->splt_line[j])
		{
			all->w_line[j] = ft_split(all->splt_line[j], '|');
			j++;
		}
	}

	all->w_line[j] = 0;
	// ft_print_tab(all->splt_line);
	ft_print_megatab(all->w_line);

	ft_free_tab(all->splt_line);
	ft_free_megatab(all->w_line);
	return (1);
}

int		ft_count_split(char *line)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == ';')
			count++;
		i++;
	}
	return (count + 1);
}

void	ft_print_tab(char **tab)
{
	int j;

	j = 0;
	while (tab[j])
	{
		printf("%s\n", tab[j]);
		j++;
	}
}

void	ft_free_tab(char **tab)
{
	int j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

void	ft_free_megatab(char ***tab)
{
	int j;

	j = 0;
	while (tab[j])
	{
		ft_free_tab(tab[j]);
		j++;
	}
	free(tab);
}


void	ft_print_megatab(char ***tab)
{
	int j;
	int i;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			printf("%s\n", tab[j][i]);
			i++;
		}
		j++;
	}
}