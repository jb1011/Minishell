/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/08/30 21:48:51 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int main(int argc, char **argv)
{
	t_all all;
	char *test;
	char *ty;
	t_slv s;

	all.path = ft_strdup("/home/louis/42/minishell");
	chdir(all.path);
	s.j = 0;
	char *t[] = {"test.sh", 0, 0};
	_fct(t, 0);
	while(42)
	{
		begin(&all);
	}
}
