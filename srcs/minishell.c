/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 13:33:14 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>

int g_status;

int main()
{
	struct termios tattr;
	t_all all;

	init(&all);
	ft_term(&tattr);
	while(42)
	{
		signal(SIGINT, ft_sigint);
		begin(&all);
		parse_line(&all);
		treatall(&all, all.env, all.pipelist);
		free_list(&all.pipelist);
		free(all.line);
	}
}