/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/01 17:47:32 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	ft_sigint(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		put_prompt(0);
	}
}

void	ft_term(t_all *all)
{

	if (!isatty (STDIN_FILENO))
	{
		ft_putstr ("not a terminal");
	}
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_iflag &= ~(ISIG | IUTF8);
	tattr.c_lflag &= ~(ICANON);
	tattr.c_cc[VQUIT] = -1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}