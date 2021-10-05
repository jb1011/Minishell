/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:00:11 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 15:42:54 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dquotes(t_slv *s, char **trgts, int fd)
{
	while (42)
	{
		s->stra = readline("dquotes<");
		s->k = ft_strlen(trgts[s->i]);
		if (s->k == ft_strlen(s->stra))
			if (!ft_strncmp(trgts[s->i], s->stra, s->k) && do_free(s->stra))
				break ;
		s->stra = ft_join_free(s->stra, "\n", 1);
		write(fd, s->stra, ft_strlen(s->stra));
		free(s->stra);
	}
}

void	in_fct(char **redirections, char **trgts, int fd)
{
	t_slv	s;

	s = (t_slv){-1, 0, 0, 0, 0, 0, 0, (char [BUFFER_SIZE + 1]){0}, 0};
	while (trgts[++s.i])
	{
		if (redirections[s.i][0] == 'p')
			dquotes(&s, trgts, fd);
		else if (redirections[s.i][0] == '<')
		{
			s.k = open(trgts[s.i], 0, S_IRUSR | S_IWUSR);
			while (assign(&s.j, read(s.k, s.strb, BUFFER_SIZE)) > 0)
			{
				s.strb[s.j] = 0;
				write(fd, s.strb, s.j - 1);
			}
			close(s.k);
		}
	}
}

void	out_fct(t_all *all, t_pipenodes *nd, int fd)
{
	int	i;
	int	*fds;

	i = -1;
	fds = (int [2]){fd, 1};
	while (nd->targets[++i])
	{
		if (nd->redir[i][0] == 'g')
		{
			fds[1] = open(nd->targets[i], 1089, S_IRUSR | S_IWUSR);
			_fct(all, nd->orders, fds);
		}
		else if (nd->redir[i][0] == '>')
		{
			fds[1] = open(nd->targets[i], 577, S_IRUSR | S_IWUSR);
			_fct(all, nd->orders, fds);
		}
	}
	if (fds[1] == 1)
		_fct(all, nd->orders, fds);
}

int	redirect_fcts(t_all *all, t_pipenodes *nd)
{
	int		fd[2];

	if (!nd->redir)
		return (_fct(all, nd->orders, (int [2]){0, 1}));
	pipe(fd);
	in_fct(nd->redir, nd->targets, fd[1]);
	close(fd[1]);
	out_fct(all, nd, fd[0]);
	close(fd[0]);
	return (1);
}
