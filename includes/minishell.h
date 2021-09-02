/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:46 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/02 16:49:25 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SHELL_PROMPT "MINISHELL:: "

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <sys/wait.h>
# include <term.h>
# define STOP_DOLLAR "\"\'$"
# define STOP_STR "\"\'$"
# define STOP_DBLQUOTE "\"$"
# define STOP_QUOTE "\'\""

typedef struct s_env
{
	char	*var;
	char	*val;
	struct	s_env *nxt;
}	t_env;

typedef struct s_all
{
	char	*line;
	char	path[400];
	char	**splt_line;
	char	***w_line;
	char	*pipendirect;
	char	**exec_paths;
	t_env	*env;
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

int	ft_count_spaces(char *line);
int _echo(t_all *all,char **opts, int place, char *redirection_or_pipes);
int dollar_case(char **buffer, char *object, int *index);
int str_case(char **buffer, char *object, int *index, char *stops);
void quotes_bool(int *boolean);
int _cd(char *path);
int     init(t_all *all);
t_env     *vardo(t_env *list, char *tofind, char *ch_val, char del);
int     advar(t_env **list, char *var, char *val);
int         printenv(t_env *list);

#endif