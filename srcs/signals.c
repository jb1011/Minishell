/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/04 16:03:24 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	ft_sigint(int signum)
{
	char *prompt;
	
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		prompt = set_prompt();
		rl_replace_line("", 0);
		rl_redisplay();
		ft_putstr(prompt);
		status = 130;
		free(prompt);
	}
}

void	ft_term(t_all *all, struct termios *tattr)
{

	if (!isatty (STDIN_FILENO))
	{
		ft_putstr ("not a terminal");
	}
	tcgetattr(STDIN_FILENO, tattr);
	tattr->c_iflag &= ~(ISIG | IUTF8);
	tattr->c_lflag &= ~(ICANON);
	tattr->c_cc[VQUIT] = -1;
	// tattr->c_cc[VERASE] = -1;
	tcsetattr(STDIN_FILENO, TCSADRAIN, tattr);
}
