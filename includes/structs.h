/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:21:52 by lgelinet          #+#    #+#             */
/*   Updated: 2021/09/23 17:19:26 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define BUFFER_SIZE 4000

typedef struct s_env
{
	char	*var;
	char	*val;
	char	is_env;
	struct	s_env *nxt;
}	t_env;

typedef	struct s_pipenodes
{
	struct	s_pipenodes *next;
	char	**targets;
	char 	**redir;
	char	**orders;
}	t_pipenodes;


typedef struct s_all
{
	char	*line;
	char	path[BUFFER_SIZE];
	char	**splt_line;
	char	***w_line;
	char	*pipendirect;
	char	**exec_paths;
	char	ctrl_c;
	t_env	*env;
	char	*tmp;
	char	**redir_cpy;
	char	**target_cpy;
	char	**order_cpy;
	int		size_redir;
	int		to_free;
	int		count_list;
	t_pipenodes *pipelist;
	
}	t_all;

#endif