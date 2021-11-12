/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:01:56 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/14 16:36:02 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_minishell(char **opts, char *shell)
{
	char	comp[BUFFER_SIZE];

	getcwd(comp, BUFFER_SIZE);
	ft_strlcat(comp, &opts[0][1], BUFFER_SIZE);
	if (ft_strncmp(comp, shell, BUFFER_SIZE))
		return (0);
	return (1);
}

int	tesdir(char *path)
{
	DIR	*test;

	test = opendir(path);
	if (!test)
		return (0);
	closedir(test);
	return (1);
}

int	fdput(int fd, char *print, char *arg1, char *arg2)
{
	int	stdout;

	stdout = dup(1);
	dup2(fd, 1);
	if (!arg1 && !arg2)
		return (0);
	if (!arg1)
		return (printf((const char *)print, arg2));
	if (!arg2)
		return (printf((const char *)print, arg1));
	return (printf((const char *)print, arg1, arg2));
}
