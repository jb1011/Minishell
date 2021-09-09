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

int	ft_count_split(char *line)
{
	int i;
	int count;
	int c;

	count = 1;
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			c++;
		if ((line[i] == '|' || line[i] == '<' || line[i] == '>') && (c % 2 == 0))
			count++;
		i++;
	}

	return (count + 1);
}

int	parse_line(t_all *all)
{
	int j;

	// check_tilde(all->line);
	count_pipe_croc(all->line, all);
	replace_double_croc(all->line);
	if (!ft_check_error(all->line))
		printf("ERRRROOROOOOOOORRRRR");
	
	if (!is_separator(all->line))
	{
		replace_quote(all->line);
		if (ft_strchr(all->line, ' '))
		{
			replace_inib_space(all->line);
			all->w_line = malloc(sizeof(char **) * 2);
			all->w_line[0] = ft_split(all->line, ' ');
			replace_back_inib_space(all->w_line[0][0]);
			all->w_line[1] = 0;
		}
		else
			megatab_malloc_simple(all);
		trim_tab(all->w_line);
	}
	else
	{
		j = 0;
		// replace_quote(all->line);
		if (!ft_strchr(all->line, ' '))
		{
			all->w_line = malloc(sizeof(char **) * ft_count_split(all->line) * 2);
			/////////
			is_pipe_inhib(all->line);
			// all->tmp = ft_dup_char(all->line);
			// all->splt_line = ft_split(all->tmp, '|');
			replace_crocs(all->line);
			all->splt_line = ft_split(all->line, '|');
			// reverse_pipe(all->splt_line);
			ft_malloc_tab(all->w_line, ft_count_split(all->line), all->splt_line);
			
			ft_free_tab(all->splt_line);
		}
		else
		{
			all->w_line = malloc(sizeof(char **) * ft_count_split(all->line));
			/////////
			is_pipe_inhib(all->line);
			replace_crocs(all->line);

			replace_inib_space(all->line);

			// ft_dup_char(all->line, all);

			// all->splt_line = ft_split(all->tmp, '|');
			// replace_crocs(all->line);
			all->splt_line = ft_split(all->line, '|');

			reverse_pipe(all->splt_line);
			
			while (all->splt_line[j])
			{
				all->w_line[j] = ft_split(all->splt_line[j], ' ');
				replace_doubleback_inib_space(all->w_line[j]);
				j++;
			}
			all->w_line[j] = 0;
			ft_free_tab(all->splt_line);
		}
		trim_tab(all->w_line);
	}
	ft_print_megatab(all->w_line);
	// if (!all->w_line)
	// 	ft_free_megatab(all->w_line);
	return (1);
}

void	trim_tab(char ***t)
{
	int j;
	int i;
	char	*tmp;

	j = 0;
	while (t[j])
	{
		i = 0;
		while (t[j][i])
		{
			if (ft_strchr(t[j][i], ' ') || ft_strchr(t[j][i], '\''))
			{
				tmp = ft_strtrim(t[j][i], " ");
				free(t[j][i]);
				t[j][i] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
}

int	is_pipe_inhib(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		if (str[i] == '|' && (count % 2 != 0))
			str[i] = '@';
		i++;
	}
	return (1);
}

void reverse_pipe(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '@')
				str[j][i] = '|';
			i++;
		}
		j++;
	}
}

void	replace_quote(char *str)
{
	int	i;
	int mybol;

	i = 0;
	mybol = 0;
	while (str[i])
	{
		if (mybol)
		{
			str[i] = ' ';
			mybol = 0;
		}
		if (str[i] == '\'' && str[i + 1] == '\'')
		{
			str[i] = ' ';
			mybol = 1;
		}
		i++;
	}
}

void count_pipe_croc(char *str, t_all *all)
{
	int i;
	int count;
	int j;

	count = 0;
	i = 0;

	while (str[i])
	{
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			count++;
		i++;
	}
	all->pipendirect = malloc(sizeof(char) * count + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!quote_is_odd(str, i))
		{

			if (str[i] == '|')
			{
				all->pipendirect[j] = str[i];
				j++;
			}
			if (str[i] == '<' && str[i + 1] == '<')
			{
				all->pipendirect[j] = 'p';
				j++;
				i++;
			}
			if (str[i] == '>' && str[i + 1] == '>')
			{
				all->pipendirect[j] = 'g';
				j++;
				i++;
			}
			if (str[i] == '<')
			{
				if (str[i - 1] != '<')
				{
					all->pipendirect[j] = str[i];
					j++;
				}
			}
			if (str[i] == '>')
			{
				if (str[i - 1] != '>')
				{
					all->pipendirect[j] = str[i];
					j++;
				}
			}
		}
		i++;
	}
	all->pipendirect[j] = 0;
	printf("PILELINE : %s\n", all->pipendirect);
}

void	replace_crocs(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && !quote_is_odd(str, i))
			str[i] = '|';
		i++;
	}
}

// void	check_tilde(char *path)
// {
// 	char	*temp;

// 	if (ft_strncmp(path, "~", ft_strlen(path)) && !quote_is_odd(path, ft_strlen(path)))
// 	{
// 		temp = ft_join_free("/home/", getenv("USER"), 0);
// 		temp = ft_join_free(temp, path + 1, 0);
// 		printf("%s\n", temp);
// 		if (chdir(temp) == -1)
// 		{
// 			free(temp);
// 			return(ft_err_msg("Wrong path"));
// 		}
// 		free(temp);
// 	}
// }

int	ft_check_error(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!quote_is_odd(s, i))
		{
			if (s[i] == '|' && s[i + 1] == '|')
				return (0);
			if (is_char_separator(s[i]))
				if (is_only_space(s, i))
					return (0);
		}
		i++;
	}
	return (1);
}

int	is_only_space(char *s, int start)
{
	start++;
	while (s[start])
	{
		if (is_char_separator(s[start]))
		{
			return (1);
		}
		if (s[start] != ' ')
			return (0);
		start++;
	}
	return (1);
}

void	replace_double_croc(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<' && s[i + 1] == '<')
		{
			s[i] = '|';
			s[i + 1] = ' ';
		}
		if (s[i] == '>' && s[i + 1] == '>')
		{
			s[i] = '|';
			s[i + 1] = ' ';
		}
		i++;
	}
	printf("line replaced : %s\n", s);
}

void	replace_inib_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		if (str[i] == ' ' && (count % 2 != 0))
			str[i] = '`';
		i++;
	}
}

void	replace_back_inib_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		if (str[i] == '`' && (count % 2 != 0))
		{
			str[i] = ' ';
		}
		i++;
	}
}

void	replace_doubleback_inib_space(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '`')
			{
				str[j][i] = ' ';
			}
			i++;
		}
		j++;
	}
}

void	ignore_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{

		
		i++;
	}
}