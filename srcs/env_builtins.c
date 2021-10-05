/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:55 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 16:06:25 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	_env(t_all *all, char **opts)
{
	t_env	*ptr;
	t_slv	s;

	if (opts[1])
		return (ft_err_msg("Env treated alone\n"));
	ptr = all->env;
	s.stra = ft_strdup("");
	while (ptr)
	{
		if (ptr->is_env)
		{
			s.stra = ft_join_free(s.stra, ft_join_free(ptr->var, "=", 0), 3);
			s.stra = ft_join_free(ft_join_free(s.stra, ptr->val,1), "\n", 1);
		}
		ptr = ptr->nxt;
	}
	write(1, s.stra, ft_strlen(s.stra));
	free (s.stra);
	return (1);
}

int	_export(t_all *all, char **opts)
{
	int	i;

	i = 0;
	while (opts[++i])
		assign_var(all, opts[i], EXPORT);
	return (1);
}

int	_unset(t_env **list, char **opts)
{
	int	i;

	i = 0;
	while (opts[++i])
		vardo(list, opts[i], 0, UNSET);
	return (1);
}
