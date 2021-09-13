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

int	ft_count_space(char *line)
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
		if ((line[i] == ' ') && (c % 2 == 0))
			count++;
		i++;
	}
	return (count + 1);
}

int	parse_line(t_all *all)
{
	all->line = ignore_quote(all->line);
	// all->line = ignore_quote_word(all->line);
	replace_inib_space(all->line);
	is_pipe_inhib(all->line);
	// printf("line after : %s", all->line);
	count_pipe_croc(all->line, all);
	init_list_var(all);
	// replace_double_croc(all->line);
	if (!ft_check_error(all->line))
		printf("ERRRROOROOOOOOORRRRR");
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
		if (str[i] == '\'' || str[i] == '"')
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
	// printf("PILELINE : %s\n", all->pipendirect);
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
	// printf("line replaced : %s\n", s);
}

void	replace_inib_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
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
		if (str[i] == '\'' || str[i] == '"')
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
				str[j][i] = ' ';
			i++;
		}
		j++;
	}
}

char	*ignore_quote(char *str)
{
	int	i;
	char	*tmp;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"')
			count++;
		if (((str[i] == '\'' && str[i - 1] == '`') || (str[i] == '"' && str[i - 1] == '`')) && (count % 2 == 0))
			str[i] = '`';
		if (((str[i] == '\'' && str[i + 1] == '\'') || (str[i] == '"' && str[i + 1] == '"')) && (count % 2 == 0))
			str[i] = '`';
		i++;
	}
	tmp = ft_dup(str, '`');
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

char	*ignore_quote_word(char *str)
{
	int	i;
	int	mybol;
	char	*tmp;

	i = 0;
	mybol = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && str[i - 1] != ' ') || (str[i] == '"' && str[i - 1] == ' '))
		{
			str[i] = '`';
			mybol = 1;
		}
		if (((str[i] == '\'' && str[i + 1] != ' ') && mybol == 1) || ((str[i] == '"' && str[i + 1] != ' ') && mybol == 1))
		{
			str[i] = '`';
			mybol = 0;
		}
		i++;
	}
	tmp = ft_dup(str, '`');
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	printf("LIGNE : %s", str);
	return (str);
}

void	init_list_var(t_all *all)
{
	int	i;

	all->stack = NULL;
	i = 0;
	all->splt_line = ft_split(all->line, '|');
	while (all->splt_line[i])
	{
		split_redir(all);
		split_target(all, all->splt_line[i]);
		split_orders(all, all->splt_line[i]);
		replace_doubleback_inib_space(all->order_cpy);
		replace_doubleback_inib_space(all->target_cpy);
		reverse_pipe(all->target_cpy);
		reverse_pipe(all->order_cpy);
		addnew(all, all->order_cpy, all->target_cpy, all->redir_cpy);
		ft_free_tab(all->order_cpy);
		ft_free_tab(all->target_cpy);
		ft_free_tab(all->redir_cpy);

		i++;
	}

	print_linked_list(all->stack);
}

void	split_redir(t_all *all)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(all->pipendirect) + 1;
	all->redir_cpy = malloc(sizeof(char *) * size);
	while (all->pipendirect[i])
	{
		all->redir_cpy[i] = malloc(sizeof(char) * 2);
		all->redir_cpy[i][0] = all->pipendirect[i];
		all->redir_cpy[i][1] = 0;
		i++;
	}
	all->size_redir = i + 1;
	all->redir_cpy[i] = 0;
}

void	split_target(t_all *all, char *str)
{
	int	i;
	int	j;
	int start;
	int	len;

	if (is_separator(str))
	{
		all->target_cpy = malloc(sizeof(char *) * (ft_count_space(str) * 2));
		i = 0;
		j = 0;
		while (str[i])
		{
			if (str[i] == '>')
			{
				if (is_redir(str[i + 1]))
					i++;
				start = i;
				i++;
				while (str[i] && !is_char_separator(str[i + 1]))
					i++;
				len = i - start;
				start++;
				all->tmp = ft_substr(str, start, len);
				j++;
			}
			if (str[i] == '<')
			{
				all->tmp = ft_substr(str, 0, i);
				j++;
				break;
			}
			if (i < ft_strlen(str))
				i++;
		}
		all->target_cpy = ft_split(all->tmp, ' ');
		free(all->tmp);
	}
	else
	{
		all->target_cpy = malloc(sizeof(char *) * 1);
		all->target_cpy[0] = 0;
	}
}

void	split_orders(t_all *all, char *str)
{
	int	i;
	int	j;
	int start;

	all->order_cpy = malloc(sizeof(char *) * (ft_count_space(str) * 2));
	i = 0;
	j = 0;
	start = 0;
	if (!is_redir_str(str))
	{
		all->tmp = ft_strdup(str);
		all->order_cpy = ft_split(all->tmp, ' ');
		return ;
	}
	while (str[i])
	{
		if (str[i] == '>')
		{
			all->tmp = ft_substr(str, start, i);
			j++;
			break ;
		}
		if (str[i] ==  '<')
		{
			if (is_redir(str[i + 1]))
				i++;
			start = i;
			i++;
			while (str[i] && !is_char_separator(str[i + 1]))
				i++;
			start++;
			all->tmp = ft_substr(str, start, i);
			j++;
			break ;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] == '|')
		{
			start = i;
			i++;
			while (str[i] && !is_char_separator(str[i + 1]))
				i++;
			start++;
			all->tmp = ft_substr(str, start, i);
			j++;
		}
		if (i < ft_strlen(str))
			i++;
	}
	all->order_cpy = ft_split(all->tmp, ' ');
	free(all->tmp);
}