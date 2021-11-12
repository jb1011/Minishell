/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:00:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/11/12 12:48:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dquotes(t_slv *s, char **trgts, int fd)
{
	while (42)
	{
		s->stra = readline("heredoc<");
		s->k = ft_strlen(trgts[s->i]);
		if (s->k == ft_strlen(s->stra))
			if (!ft_strncmp(trgts[s->i], s->stra, s->k) && do_free(s->stra))
				break ;
		s->stra = ft_join_free(s->stra, "\n", 1);
		write(fd, s->stra, ft_strlen(s->stra));
		free(s->stra);
	}
}

void	in_fct(char **redir, char **trgts, int fd)
{
	t_slv	s;

	s = (t_slv){0, 0, 0, 0, 0, -1, "l", (char [BUFFER_SIZE + 1]){0}, 0};
	while (trgts[++s.la])
	{
		if (redir[s.la][0] == '<' && assign(&s.i, tesdir(trgts[s.la])))
			break ;
		if (redir[s.la][0] == 'p')
			dquotes(&s, trgts, fd);
		else if (redir[s.la][0] == '<')
		{
			if (assign(&s.k, open(trgts[s.la], 0, S_IRUSR | S_IWUSR)) < 0)
				break ;
			while (assign(&s.j, read(s.k, s.strb, BUFFER_SIZE)) > 0)
			{
				s.strb[s.j] = 0;
				write(fd, s.strb, s.j - 1);
			}
			close(s.k);
		}
	}
	if (s.k == -1)
		fdput(2, "minishell: %s: %s\n", trgts[s.la], DIRRER);
}

void	out_fct(t_all *all, t_pipenodes *nd, int fd, char **t)
{
	t_slv	s;

	s = (t_slv){-1, 0, 0, 0, 0, 0, 0, 0, (int [2]){fd, 1}};
	while (t[++s.i])
	{
		if (nd->redir[s.i][0] == 'g' || nd->redir[s.i][0] == '>')
			if (assign(&s.j, tesdir(t[s.i])) == 1)
				break ;
		if (t[s.i][0] == '/')
			break ;
		if (nd->redir[s.i][0] == 'g')
		{
			s.t[1] = open(t[s.i], 1089, S_IRUSR | S_IWUSR);
			_fct(all, nd->orders, s.t);
		}
		else if (nd->redir[s.i][0] == '>')
		{
			s.t[1] = open(t[s.i], 577, S_IRUSR | S_IWUSR);
			_fct(all, nd->orders, s.t);
		}
	}
	if (t[s.i] && t[s.i][0] == '/')
		fdput(2, "minishell: %s :  Permission denied\n", t[s.i], 0);
	if (s.t[1] == 1)
		_fct(all, nd->orders, s.t);
}

int	redirect_fcts(t_all *all, t_pipenodes *nd)
{
	int		fd[2];

	if (!nd->redir)
		return (_fct(all, nd->orders, (int [2]){0, 1}));
	pipe(fd);
	in_fct(nd->redir, nd->targets, fd[1]);
	close(fd[1]);
	out_fct(all, nd, fd[0], nd->targets);
	close(fd[0]);
	return (1);
}
