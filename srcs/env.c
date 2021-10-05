/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:39:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 16:18:55 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

int	advar(t_env **list, char *var, char *val, char is_env)
{
	t_env	*ret;

	ret = malloc(sizeof(t_env));
	ret->var = ft_strdup(var);
	ret->val = ft_strdup(val);
	ret->nxt = *list;
	ret->is_env = is_env;
	*list = ret;
	return (1);
}

t_env	*vardo(t_env **list, char *tofind, char *ch_val, char do_what)
{
	t_env	*ret;
	t_env	*temp;

	temp = NULL;
	ret = *list;
	if (!*list)
		return (NULL);
	while (ret && ft_strncmp(ret->var, tofind, ft_strlen(ret->var)))
	{
		temp = ret;
		ret = ret->nxt;
	}
	if (ch_val && ret && do_free(ret->val))
		ret->val = ft_strdup(ch_val);
	if (ret && do_what == EXPORT)
		ret->is_env = 1;
	if (do_what != UNSET || !ret)
		return (ret);
	if (!temp)
		*list = ret->nxt;
	else
		temp->nxt = ret->nxt;
	if (do_free(ret->var) && do_free(ret->val) && do_free(ret))
		return (NULL);
}

char	**env_to_strtab(t_env *list)
{
	t_env	*ptr;
	int		i;
	char	**ret;

	i = 0;
	if (!list)
		return (0);
	ptr = list;
	while (ptr && ++i)
		ptr = ptr->nxt;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = NULL;
	ptr = list;
	i = -1;
	while (ret[++i])
	{
		ret[i] = ft_join_free(ft_strjoin(ptr->var, "="), ptr->val, 1);
		ptr = ptr->nxt;
	}
	return (ret);
}

int	free_env(t_env **env)
{
	t_env	*ptr;

	ptr = *env;
	while (ptr)
	{
		ptr = *env;
		*env = (*env)->nxt;
		if (ptr->var)
			free(ptr->var);
		if (ptr->val)
			free(ptr->val);
		free(ptr);
	}
	return (1);
}
