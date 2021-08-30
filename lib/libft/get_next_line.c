/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet@student.42.fr <lgelinet>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:52:52 by lgelinet          #+#    #+#             */
/*   Updated: 2021/07/13 15:26:39 by lgelinet@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 1080

int	ft_keeped_case(char **line, char *keeped, int n_occur)
{
	unsigned int	ret_len;

	*line = ft_substr(keeped, 0, n_occur - 1);
	ret_len = ft_strlen(keeped + n_occur) + 1;
	ft_memmove(keeped, keeped + n_occur, ret_len);
	return (1);
}

int	assign(int *tochange, int fct)
{
	*tochange = fct;
	return (fct);
}

int	lastkeep(char **line, char *keeped)
{
	*line = ft_strdup(keeped);
	free(keeped);
	keeped = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*keeped = NULL;
	t_slv		s;

	s.stra = (char [BUFFER_SIZE + 1]){};
	if (fd < 0 || !line || read(fd, s.stra, 0) < 0)
		return (-1);
	if (keeped && assign(&s.j, ft_rankchr(keeped, '\n')))
		return (ft_keeped_case(line, keeped, s.j));
	if (!keeped)
		keeped = ft_strdup("");
	while (assign(&s.k, read(fd, s.stra, BUFFER_SIZE)))
	{
		s.stra[s.k] = '\0';
		keeped = ft_join_free(keeped, s.stra, 1);
		if (assign(&s.j, ft_rankchr(keeped, '\n')))
			return (ft_keeped_case(line, keeped, s.j));
	}
	return (lastkeep(line, keeped));
}
