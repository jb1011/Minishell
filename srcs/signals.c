/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/30 15:33:53 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

struct termios saved_att;

void	ft_sigint(int signum, t_all *all)
{
	if (signum == SIGINT)
	{
		// ft_putstr("\n");
		// ft_bzero(all->path, BUFFER_SIZE - 1);
		// getcwd(all->path, BUFFER_SIZE - 1);
		// printf("%s %s-> \n", all->path, SHELL_PROMPT);
	}
	if (signum == SIGQUIT)
	{
		// _myexit(all);
		// ft_putstr("\n");
		return ;
	}
	if (signum == SIGSEGV)
	{
		// printf("hey");
		exit (1);
		// return ;
	}
}

void	ft_term(t_all *all)
{
	struct termios tattr;

	char *name;
	if (!isatty (STDIN_FILENO))
	{
		printf ("not a terminal");
	}
	tcgetattr(STDIN_FILENO, &saved_att);

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_cc[VINTR] = 0; /*CTRL C*/
	tattr.c_cc[VEOF] = 0; /*CTRL D*/
	tattr.c_cc[VQUIT] = 0; /*CTRL \*/
    // all->line = readline("\n");

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
	// return (NULL);
}