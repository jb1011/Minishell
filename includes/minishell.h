/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:46 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/30 12:36:34 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SHELL_PROMPT "MINISHELL:: "

# include "libft.h"
# include "structs.h"
# include <readline/readline.h>
# include <readline/history.h>
// # include <curses.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <fcntl.h>
# define STOP_DOLLAR "\"\'$"
# define STOP_STR "\"\'$"
# define STOP_DBLQUOTE "\"$"
# define STOP_QUOTE "\'\""
# define DEL_ALL 1
# define UNSET 2
# define EXPORT 3
# define PRINT	4
# define PURPLE


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
void	split_redir(t_all *all, char *str);
char	*ignore_quote_word(char *str);
int		is_redir(char s);
void	split_target(t_all *all, char *str);
void	split_orders(t_all *all, char *str);
void	init_list_var(t_all *all);
void	print_linked_list(t_pipenodes *pipelist);
char	**mall_doubletab(char **t);
int		is_redir_str(char *s);
void	ft_sigint(int signum, t_all *all);
int		ft_count_redir(char *line);
void	rpl_space(char *str, int start, int len);
int		_myexit(t_all *all);
void	ft_putchar(char c);
void	free_list(t_pipenodes *st);
void	free_for_all(t_all *all);
void	reorder_tabs(char *str);
void	ft_free_order(char **t, t_all *all);
int 	ft_get_nb_strs(char *s, char c);
int     ft_count_pipes(t_all *all);
void    ft_term(t_all *all);

t_pipenodes	*createCell(char **orders, char **targets, char **redir);
int	is_empty(t_pipenodes *pipelist);
void	addnew(t_all *all, char **orders, char **targets, char **redir);

int	ft_count_spaces(char *line);
int dollar_case(char **buffer, char *object, int *index, t_all *all);
int str_case(char **buffer, char *object, int *index, char *stops);
void quotes_bool(int *boolean);
int     free_env(t_env **env);

/* ENVIRONNEMENT GESTION */
t_env	*vardo(t_env **list, char *tofind, char *ch_val, char do_what);
int		advar(t_env **list, char *var, char *val, char is_env);
int		assign_var(t_all *all, char *assignation, char export);
char	**env_to_strtab(t_env *list);
int		init(t_all *all);


/* BUILTINS */
int		_echo(t_all *all,char **opts);
int		_env(t_all *all,char **opts);
int		_unset(t_env **list, char **opts);
int		_export(t_all *all, char **opts);
int     my_exit(t_all *all, char **order);
int		_pwd(t_all *all);
int		_cd(char *path);

/* BUILTINS UTILS*/
int     assign_var(t_all *all, char *assignation, char export);
int     is_builtins(char **opts);

/*ORDERS TREATMENT*/
int		changeline(t_all *all, char **line);
int		do_builtins(t_all *all, char **opts, int no_builtins);
int		isfct(char **path, char **fct);
int     treat_orders(t_all *all, t_pipenodes *node);
/* REDIRECTIONS !!!!!!!!!!! */
int		_fct(t_all *all,char *todo[], char *env[], int stdin , int stdout);
int		redirect_fcts(t_all *all, char **redirections, char **targets, char *todo[], char *env[]);

/* PIPES */
int     piping(t_all *all, t_env *env, t_pipenodes *nd);
#endif