/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/10 13:25:34 by lgelinet         ###   ########.fr       */
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
		begin(&all);
		parse_line(&all);
		signal(SIGINT, ft_sigint);
		//  printf("%s\n", all.w_line[0][1]);
		// _echo(0, all.w_line[0], 0, 0);
		//printf("%s\n", all.w_line[0][1]);
		// _echo(&all, all.w_line[0], 0, 0);
		// _cd("~");
		// _env(&all, all.w_line[0], 0, 0);
		// printf("|%s|\n",  all.stack->orders[1]);
		//treat_orders(&all, all.stack->orders);
	}
}
