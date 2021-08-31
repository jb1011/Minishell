/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/08/31 14:49:47 by lgelinet         ###   ########.fr       */
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
	char *ty;
	t_slv s;

	ty = malloc(400);
	all.path = ft_strdup("/home");
	chdir(all.path);
	s.j = 0;
	//tputs("echo hi\n", getpid(), 0);
	//char *t[] = {"/bin/ls", ">", "hi", 0};
	//char *env[] = {"", "ARG2", 0};
	//_fct(t, env);
	char id = fork();
	while(42)
	{
		begin(&all);
	}
}
