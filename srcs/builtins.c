#include "../includes/minishell.h"
#include <stdlib.h>
#include <unistd.h>


int _cd(char *path)
{
    if (chdir(path) == -1)
        return (ft_err_msg("Wrong path"));
    return (1);
}

int _pwd(t_all *all)
{
    printf("%s\n", all->path);
    return (1);
}

int _echo(t_all *all,char **opts, int place, char *redirection_or_pipes)
{
    t_slv s;

    s = (t_slv){-1, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
    ++opts;
    if (!ft_memcmp(*opts, "-n", 3) && ++opts)
        s.da = 1;
    if (!opts)
        return (0);
    s.strb = *opts;
    while (s.strb[++s.i])
    {
        if (s.strb[s.i] == '\"' && !s.j)
            quotes_bool(&s.k);
        else if (s.strb[s.i] == '\'' && !s.k) 
            quotes_bool(&s.j);
        else if (s.j) // s.j --->> apostrophe !!!!!!
            str_case(&s.stra, s.strb, &s.i, STOP_QUOTE);
        else if (s.strb[s.i] == '$')
            dollar_case(&s.stra, s.strb, &s.i, all);
        else if (s.k) // s.k -->>> GUILLEMETS
            str_case(&s.stra, s.strb, &s.i, STOP_DBLQUOTE);
        else
        {
            str_case(&s.stra, s.strb, &s.i, STOP_STR);
        }
        if (!s.strb[s.i + 1] && ++opts && *opts && assign(&s.i, -1) == - 1)
        {
            s.stra = ft_join_free(s.stra, " ", 1);
            s.strb = *opts;
        }
    }
    if (!s.da)
        s.stra = ft_join_free(s.stra, "\n", 1);
    if (!redirection_or_pipes || ft_strlen(redirection_or_pipes) < place)
        ft_putstr(s.stra);
    free(s.stra);
    return (1);
}

int     _env(t_all *all,char **opts, int place, char *redirection_or_pipes)
{
    t_env   *ptr;
    t_slv   s;

    if (opts[1])
        return (ft_err_msg("Env treated alone"));
    if ((!redirection_or_pipes || ft_strlen(redirection_or_pipes) < place))
        s.k = 1;
    else
        s.k = 0;;
    ptr = all->env;
    s.stra = ft_strdup("");
    while (ptr)
    {
        if (s.k)
            printenv(ptr);
        else
            printf("af faire plus tard\n");
        ptr = ptr->nxt;
    }
    return (1);
}

int     _unset(t_env **list, char **opts)
{
    int i;
    i = 0;
    while (opts[++i])
        vardo(list, opts[i], 0, 1);
}