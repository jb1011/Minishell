/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:22:57 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/07 13:33:48 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	_env(t_all *all, char **opts)
{
	char	**env;
	int		i;

	i = -1;
	if (opts[1])
		return (ft_err_msg("Env treated alone\n"));
	env = env_to_strtab(all->env);
	while (env[++i])
	{
		printf("%s\n", env[i]);
		free(env[i]);
	}
	free(env[i]);
	free(env);
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
