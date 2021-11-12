/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:31:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/12 22:43:43 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_status;

int	main(int argc, char **argv)
{
	struct termios	tattr;
	t_all			all;

	if (argc != 1)
		printf("No argument needed\n");
	init(&all, *argv);
	ft_term(&tattr);
	while (42)
	{
		signal(SIGINT, ft_sigint);
		begin(&all);
		parse_line(&all);
		treatall(&all, all.env, all.pipelist);
		free_list(&all.pipelist);
		free(all.line);
	}
}
