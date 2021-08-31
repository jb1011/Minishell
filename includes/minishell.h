/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:46 by lgelinet          #+#    #+#             */
/*   Updated: 2021/08/30 21:46:46 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# define SHELL_PROMPT "\nMINISHELL:: "
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <sys/wait.h>
# include <term.h>

typedef struct s_all
{
	char    *line;
    char    *path;
    char    pipe;
    char    croco;
    char    doublecroco;
}	t_all;

int	_fct(char *todo[], char *env[]);
int     begin(t_all *all);
#endif