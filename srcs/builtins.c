/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:29:12 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/14 14:58:37 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	_cd(char *path, t_all *all)
{
	if (!path || !path[0] || path[0] == '~')
	{
		ft_strlcpy(all->old_path, all->path, ft_strlen(all->path) + 1);
		chdir("");
		return (1);
	}
	if (*path == '-')
	{
		printf("%s\n", all->old_path);
		chdir(all->old_path);
		ft_strlcpy(all->old_path, all->path, ft_strlen(all->path) + 1);
		return (1);
	}
	if (chdir(path) == -1)
	{
		perror(path);
		return (0);
	}
	ft_strlcpy(all->old_path, all->path, ft_strlen(all->path) + 1);
	return (1);
}

int	_pwd(t_all *all)
{
	printf("%s\n", all->path);
	return (1);
}

int	assign_var(t_all *all, char *assignation, char export)
{
	int		i;
	char	*temp;
	char	*value;

	i = ft_rankchr(assignation, '=');
	if (!i)
		value = NULL;
	else
		value = ft_strdup(&assignation[i]);
	temp = extractstr(assignation, "=");
	if (!vardo(&all->env, temp, value, export))
		advar(&all->env, temp, value, export);
	return (1);
}

int	_echo(t_all *all, char **opts)
{
	t_slv	s;

	(void)all;
	s = (t_slv){0, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
	if (opts[1] && !ft_memcmp(opts[1], "-n", 2))
		while (!ft_memcmp(opts[++s.j], "-n", 2) && ++s.i)
			s.k = 1;
	while (opts[++s.i])
	{
		s.stra = ft_join_free(s.stra, opts[s.i], 1);
		if (opts[s.i + 1])
			s.stra = ft_join_free(s.stra, " ", 1);
	}
	if (!s.k)
		s.stra = ft_join_free(s.stra, "\n", 1);
	write(1, s.stra, ft_strlen(s.stra));
	free(s.stra);
	return (1);
}

int	_myexit(t_all *all)
{
	int			ret;
	t_winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	if (w.ws_col > 900)
	{
		w.ws_col = 100;
		ioctl(0, TIOCSWINSZ, &w);
	}
	printf("exit\n");
	if (all->pipelist->orders[1] != NULL)
		ret = ft_atoi(all->pipelist->orders[1]);
	free_list(&all->pipelist);
	all->pipelist = NULL;
	if (all->line)
		free(all->line);
	exit(ret);
	return (0);
}
