/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/30 12:36:34 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>


int main()
{
	t_all all;
	// char *test;
	// t_slv s;

	init(&all);
	while(42)
	{
		signal(SIGINT, &ft_sigint);
		begin(&all);
		parse_line(&all);
		piping(&all, all.env, all.pipelist);
		printf("END ORDER \n");
	}
}
