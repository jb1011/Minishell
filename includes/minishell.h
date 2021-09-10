/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:46 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/09 21:57:57 by lgelinet         ###   ########.fr       */
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
# define DEL_ALL 1
# define UNSET 2
# define EXPORT 3
# define PRINT	4

typedef struct s_env
{
	char	*var;
	char	*val;
	char	is_env;
	struct	s_env *nxt;
}	t_env;

typedef	struct	s_pipenodes
{
	struct	s_pipenodes *next;
	char	**targets;
	char 	**redir;
	char	**orders;
} t_pipenodes;


typedef struct s_all
{
	char	*line;
	char	path[400];
	char	**splt_line;
	char	***w_line;
	char	*pipendirect;
	char	**exec_paths;
	t_env	*env;
	char	*tmp;
	char	**redir_cpy;
	char	**target_cpy;
	char	**order_cpy;
	int		size_redir;
	t_pipenodes *stack;
	
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
int		is_separator(char *s);
int		quote_is_odd(char *s, int end);
void	check_tilde(char *path);
void	megatab_malloc_simple(t_all *all);
int		ft_check_error(char *s);
int		is_only_space(char *s, int start);
int		is_char_separator(char c);
void	replace_double_croc(char *s);
void	replace_back_inib_space(char *str);
void	replace_inib_space(char *str);
void	replace_doubleback_inib_space(char **str);
char	*ft_dup(const char *s, char c);
char	*ignore_quote(char *str);
void	split_redir(t_all *all);
char	*ignore_quote_word(char *str);
int		is_redir(char s);
void	split_target(t_all *all, char *str);
void	split_orders(t_all *all, char *str);
void	init_list_var(t_all *all);
void	print_linked_list(t_pipenodes *stack);
char	**mall_doubletab(char **t);
int		is_redir_str(char *s);

t_pipenodes	*createCell(char **orders, char **targets, char **redir);
int	is_empty(t_pipenodes *stack);
void	addnew(t_all *all, char **orders, char **targets, char **redir);

int	ft_count_spaces(char *line);
int dollar_case(char **buffer, char *object, int *index, t_all *all);
int str_case(char **buffer, char *object, int *index, char *stops);
void quotes_bool(int *boolean);
int     treat_orders(t_all *all, char **opts);
/* ENVIRONNEMENT GESTION */
int     init(t_all *all);
t_env     *vardo(t_env **list, char *tofind, char *ch_val, char do_what);
int     advar(t_env **list, char *var, char *val, char is_env);
int         printenv(t_env *env);
char    **env_to_strtab(t_env *list);
int     assign_var(t_all *all, char *assignation, char export);
/* BUILTINS */
int _echo(t_all *all,char **opts, int place, char *redirection_or_pipes);
int _cd(char *path);
int     _env(t_all *all,char **opts, int place, char *redirection_or_pipes);
int     _unset(t_env **list, char **opts);
int _pwd(t_all *all);
int     _export(t_all *all, char **opts);

#endif