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
    char *temp;

    s = (t_slv){0, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
    if (!ft_memcmp(*opts, "-n", 3) && ++s.i)
        s.k = 1;
    while (opts[++s.i])
        s.stra = ft_join_free(ft_join_free(s.stra, " ", 1), opts[s.i], 1);
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
        if (s.k && ptr->is_env)
            printenv(ptr);
        else if (ptr->is_env)
            printf("af faire plus tard\n");
        ptr = ptr->nxt;
    }
    return (1);
}

int     _export(t_all *all, char **opts)
{
    int i;

    i = 0;
    while (opts[++i])
        assign_var(all, opts[i], EXPORT);
}
int     _unset(t_env **list, char **opts)
{
    int i;
    i = 0;
    while (opts[++i])
        vardo(list, opts[i], 0, UNSET);
    return (1);
}