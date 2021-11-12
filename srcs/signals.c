/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:41:10 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/12 22:35:21 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sigint(int signum)
{
	char	*prompt;

	if (signum == SIGINT)
	{
		prompt = set_prompt();
		rl_replace_line("", 0);
		rl_on_new_line();
		write(1, "\n", 1);
		rl_redisplay();
		g_status = 130;
		free(prompt);
	}
}

void	ft_term(struct termios *tattr)
{
	tcgetattr(STDIN_FILENO, tattr);
	tattr->c_oflag &= ~(ONLRET);
	tattr->c_lflag &= ~(ICANON);
	tattr->c_cflag &= ~(CLOCAL);
	tattr->c_cc[VQUIT] = -0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, tattr);
}
