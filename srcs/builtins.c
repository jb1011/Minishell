#include "../includes/minishell.h"

int _cd(char *path)
{
	if (!path || !path[0])
	{
		chdir("/home");
		return (1);
	}
	if (chdir(path) == -1)
		return (ft_err_msg("Wrong path\n"));
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

	(void)all;
	s = (t_slv){0, 0, 0, 0, 0, 0, ft_strdup(""), 0, 0};
	// printf("opts[0] == %s\n opts[1] == %s\n opts[2] == %s\n", opts[0], opts[1], opts[2]);
	if (!ft_memcmp(opts[1], "-n", 3) && ++s.i)
		s.k = 1;
	while (opts[++s.i])
	{
		s.stra = ft_join_free(s.stra , opts[s.i], 1);
		if (opts[s.i + 1])
			s.stra = ft_join_free(s.stra, " ", 1);
	}
	if (!s.k)
		s.stra = ft_join_free(s.stra, "\n", 1);
	write(1, s.stra, ft_strlen(s.stra));
	free(s.stra);
	return (1);
}

int _myexit(t_all *all)
{
	int status;
	// ft_free_tab(all->order_cpy);
	// ft_free_tab(all->redir_cpy);
	// ft_free_tab(all->target_cpy);
	printf("exit\n");
	if (all->pipelist->orders[1] != NULL)
		ft_atoi(all->pipelist->orders[1]);
	else
		status = 0;
	free_list(all->pipelist);
	// ft_print_tab(all->order_cpy);
	// // free_for_all(all);
	// printf("exit\n");
	exit(status);
	return (0);
}