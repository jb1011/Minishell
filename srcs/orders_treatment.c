/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:25 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/14 17:14:00 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtins(char **opts, t_all *all)
{
	int	len;

	if (assign(&len, ft_rankchr(*opts, '=')))
		if (!(!opts[0][len] && opts[1]))
			return (6);
	len = ft_strlen(*opts) + 1;
	if (len == 7)
		if (!ft_strncmp(*opts, "export", 7))
			return (1);
	if (len == 6)
		if (!ft_strncmp(*opts, "unset", 6))
			return (2);
	if (len == 5)
		if (!ft_strncmp(*opts, "echo", 5))
			return (3);
	if (len == 4 && !ft_strncmp(*opts, "pwd", 4))
		return (4);
	if (len == 4 && !ft_strncmp(*opts, "env", 4))
		return (5);
	if (is_minishell(opts, all->minishell))
		return (7);
	return (0);
}

int	do_builtins(t_all *all, char **opts, int no_builtins)
{
	if (!no_builtins)
		return (0);
	if (no_builtins == 1)
		return (_export(all, opts));
	if (no_builtins == 2)
		return (_unset(&all->env, opts));
	if (no_builtins == 3)
		return (_echo(all, opts));
	if (no_builtins == 4)
		return (_pwd(all));
	if (no_builtins == 5)
		return (_env(all, opts));
	if (no_builtins == 6 && all->count_list == 1)
		return (assign_var(all, *opts, 0));
	if (no_builtins == 6)
		return (write(1, "\0", 1));
	if (no_builtins == 7)
		return (forkexec(opts, all->env));
	return (0);
}

int	isfct(char **path, char **fct)
{
	int		fd;
	int		i;
	char	*buff;

	i = 0;
	buff = ft_join_free(ft_strjoin(path[0], "/"), *fct, 1);
	while (assign(&fd, open(buff, O_RDONLY)) < 1 && path[++i])
	{
		free(buff);
		buff = ft_join_free(ft_strjoin(path[i], "/"), *fct, 1);
		close (fd);
	}
	free (buff);
	if (!path[i])
	{
		g_status = 127;
		printf("%s : command not found\n", *fct);
		return (0);
	}
	close(fd);
	*fct = ft_join_free(ft_strjoin(path[i], "/"), *fct, 3);
	return (1);
}

int	setting_node(t_all *all, t_pipenodes *node)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = *node->orders;
	if (*tmp == '~' && tmp[1] == '=' && assign(&g_status, 127))
		return (fdput(2, "%s: command not found\n", tmp, 0));
	if (*tmp == '~')
		i++;
	while (node->orders[++i])
		changeline(all, &node->orders[i]);
	i = -1;
	if (node->targets)
		while (node->targets[++i])
			changeline(all, &node->orders[i]);
	return (0);
}

int	treat_orders(t_all *all, t_pipenodes *node)
{
	int	len;

	if (!node || !(node->orders))
		return (0);
	if (setting_node(all, node))
		return (0);
	len = ft_strlen(node->orders[0]);
	if (len == 4 && !ft_strncmp("exit", node->orders[0], 4))
		return (_myexit(all));
	if (len == 2 && !ft_strncmp(node->orders[0], "cd", len))
		return (_cd(node->orders[1], all));
	redirect_fcts(all, node);
	return (1);
}
