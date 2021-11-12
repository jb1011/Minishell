/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapting_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 00:56:20 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/07 14:32:27 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	dollar_case(char **buffer, char *object, int *index, t_all *all)
{
	int		k;
	char	*temp;
	t_env	*env;

	if (object[*index + 1] == '$' && ++*index)
		*buffer = ft_join_free(*buffer, ft_itoa(getpid()), 3);
	else if (object[*index + 1] == '?' && ++*index)
		*buffer = ft_join_free(*buffer, ft_itoa(g_status), 3);
	else if (!object[*index + 1])
		*buffer = ft_join_free(*buffer, "$", 1);
	else
	{
		k = *index + 1;
		while (!ft_strchr(STOP_DOLLAR, object[++*index]))
			;
		temp = extractstr(&object[k], STOP_DOLLAR);
		env = vardo(&all->env, temp, 0, 0);
		if (env)
			*buffer = ft_join_free(*buffer, env->val, 1);
		free(temp);
		--*index;
		return (0);
	}
	return (1);
}

int	str_case(char **buffer, char *object, int *index, char *stops)
{
	int		k;
	char	*temp;

	k = *index;
	while (!ft_strchr(stops, object[++*index]))
		;
	temp = extractstr(&object[k], stops);
	*buffer = ft_join_free(*buffer, temp, 3);
	--*index;
	if (object[*index + 1])
		return (1);
	return (0);
}

void	quotes_bool(int *boolean)
{
	if (!*boolean)
		++*boolean;
	else
		*boolean = 0;
}

int	changeline(t_all *all, char **line)
{
	t_slv	s;

	if (!*line)
		return (1);
	s = (t_slv){-1, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
	if (**line == '~' && !++s.i)
		s.stra = ft_join_free(s.stra, ft_strjoin("/home/", getenv("USER")), 3);
	while ((*line)[++s.i])
	{
		if ((*line)[s.i] == '\"' && !s.j)
			quotes_bool(&s.k);
		else if ((*line)[s.i] == '\'' && !s.k)
			quotes_bool(&s.j);
		else if (s.j)
			str_case(&s.stra, (*line), &s.i, STOP_QUOTE);
		else if ((*line)[s.i] == '$')
			dollar_case(&s.stra, (*line), &s.i, all);
		else if (s.k)
			str_case(&s.stra, (*line), &s.i, STOP_DBLQUOTE);
		else
			str_case(&s.stra, (*line), &s.i, STOP_STR);
	}
	free(*line);
	*line = s.stra;
	return (1);
}
