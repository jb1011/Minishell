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

# define SHELL_PROMPT "\nMINISHELL:: "

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <sys/wait.h>
# include <term.h>

typedef struct s_all
{
	char	*line;
	char	pipe;
	char	croco;
	char	doublecroco;
	char	*path;
	char	**splt_line;
	char	***w_line;
	char	*pipendirect;
	char	*tmp;
}	t_all;

int		_fct(char *todo[], char *env[]);
int		begin(t_all *all);
int		parse_line(t_all *all);
void	ft_print_tab(char **t);
void	ft_free_tab(char **t);
void	ft_print_megatab(char ***t);
int		ft_count_split(char *line);
void	ft_free_megatab(char ***t);
void	trim_tab(char ***t);
int		ft_count_spaces(char *line);
int		is_pipe_inhib(char *str);
void 	reverse_pipe(char **str);
void	replace_quote(char *str);
void	count_pipe_croc(char *str,t_all *all);
char	*ft_dup_char(const char *s);
void	replace_crocs(char *str);
void	ft_malloc_tab(char ***t, int size, char **s);



#endif