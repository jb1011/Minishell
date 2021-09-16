/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:22 by lgelinet         ###   ########.fr       */
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

	init(&all);
	while(42)
	{
		signal(SIGINT, ft_sigint);
		begin(&all);
		parse_line(&all);
		//  printf("%s\n", all.w_line[0][1]);
		// _echo(0, all.w_line[0], 0, 0);
		//printf("%s\n", all.w_line[0][1]);
		// _echo(&all, all.w_line[0], 0, 0);
		// _cd("~");
		// _env(&all, all.w_line[0], 0, 0);
		// printf("|%s|\n",  all.stack->orders[1]);

		treat_orders(&all, all.stack);

		//int c = open("prout.txt",O_CREAT | O_WRONLY |  O_APPEND, S_IRUSR | S_IWUSR);
		//dup2(c, 1);
		//execve("/usr/bin/ls", (char *[2]){"ls", 0}, 0);
		// while(all.stack->targets[++i])
			// printf("||||||targets %d --> %s", i , all.stack->targets[i]);
		// printf("%s\n%sifhjweuifhweuifhwefuh\n", all.env->var, all.env->val);
	}
}
