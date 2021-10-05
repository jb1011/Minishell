/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet <lgelinet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:18:42 by lgelinet          #+#    #+#             */
/*   Updated: 2021/10/05 15:50:45 by lgelinet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>

# define NBRS "0123456789"

typedef struct s_slv
{
	int			i;
	int			j;
	int			k;
	double		da;
	double		db;
	long long	la;
	char		*stra;
	char		*strb;
	int			*tab;
}	t_slv;

typedef struct s_list
{
	void			*p;
	struct s_list	*next;
}	t_list;

void			*ft_memset(void *s, int c, int n);
void			ft_bzero(void *s, int n);
void			*ft_memcpy(void *dest, const void *src, int n);
void			*ft_memccpy(void *dst, const void *src, int c, int n);
void			*ft_memmove(void *dest, const void *src, int n);
void			*ft_memchr(const void *s, int c, int n);
void			ft_putnbr_fd(int n, int fd);
void			*ft_calloc(int nmemb, int size);
int				ft_memcmp(const void *s1, const void *s2, int n);
int				ft_strlen(const char *s);
int				near(double nb);
int				assign(int *tochange, int fct);
int				ft_isalpha(int c);
t_list			*new_lst(char *ptr);
int				add_front(t_list **l, void *ptr);
int				lst_last(t_list *l);
int				clear_lst(t_list **l);
int				pure_set(char *set, char *str);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_putstr(char *s);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				get_next_line(int fd, char **line);
int				ft_abs(int to_abs);
int				ft_pow(int nb, int power);
int				xtrms(int *tab, int size, char what);
int				ft_sqrt(int nb);
int				ft_iswhitespace(int c);
int				do_free(void *freed);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_strlcpy(char *dst, const char *src, int size);
int				ft_err_msg(char *s);
int				ft_rankchr(char *s, char c);
int				ft_strlcat(char *dst, const char *src, int size);
int				ft_doubletabintset(int **tab, int lenght, int withd);
int				checkorder(int *a, int size);
int				ft_atoi(char *s);
char			*ft_strnstr(const char *big, const char *little, int len);
char			*ft_substr(char const *s, unsigned int start, int len);
char			*ft_strdup(void *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int nb);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_join_free(char *s1, char *s2, int freed);
char			*ft_strchr(const char *s, int c);
double			ft_atof(char *str);
int				argvsrch(char **tab, char find);
char			*chartostr(char c);
char			*extractstr(char *str, char *set_to_stop);
char			**ft_split2(char const *s, char c, char d, char f);
int				free_doubletab(char **tab);

#endif
