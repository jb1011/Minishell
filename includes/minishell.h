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

typedef struct s_all
{
	char    *line;
	char    *path;
	char	**splt_line;
	char	**splt_pipe;
	char    ***w_line;
}	t_all;

int	_fct(char *todo[], char *env[]);
int     begin(t_all *all);
int    parse_line(t_all *all);
void	ft_print_tab(char **tab);
void	ft_free_tab(char **tab);
void	ft_print_megatab(char ***tab);
int		ft_count_split(char *line);
void	ft_free_megatab(char ***tab);

#endif