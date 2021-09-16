#include "../includes/minishell.h"

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

int     assign_var(t_all *all, char *assignation, char export)
{
    int i;
    int k;
    char *temp;
    char  *value;

    i = ft_rankchr(assignation, '=');
    if (!i)
        value = NULL;
    else
        value =  &assignation[i];
    temp = extractstr(assignation, "=");
    if (!vardo(&all->env, temp, value, export))
        advar(&all->env, temp, value, export);
    return (1);
}

int _echo(t_all *all,char **opts)
{
    t_slv s;
    char *temp;

    s = (t_slv){0, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
    if (!ft_memcmp(*opts, "-n", 3) && ++s.i)
        s.k = 1;
    while (opts[++s.i])
        s.stra = ft_join_free(ft_join_free(s.stra, " ", 1), opts[s.i], 1);
    if (!s.k)
        s.stra = ft_join_free(s.stra, "\n", 1);
    ft_putstr(s.stra);
    free(s.stra);
    return (1);
}

// int _myexit(t_all *all)
// {
// 	// ft_free_tab(all->order_cpy);
// 	// ft_free_tab(all->redir_cpy);
// 	// ft_free_tab(all->target_cpy);

//     // free_list(all->stack->orders);
//     free_for_all(all);
//     printf("exit\n");
//     exit(1);
//     return (0);
// }