/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/02 13:20:51 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	t_all all;
	char *test;
	t_slv s;

	ft_strlcpy(all.path, "/home",6);
	chdir(all.path);
	s.j = 0;
	//tputs("echo hi\n", getpid(), 0);
	//char *t[] = {"/bin/ls", ">", "hi", 0};
	//char *env[] = {"", "ARG2", 0};
	//_fct(t, env);
	while(42)
	{
		begin(&all);
		parse_line(&all);
		printf("%s\n", all.w_line[0][1]);
		//_echo(0, all.w_line[0], 0, 0);
	}
}
