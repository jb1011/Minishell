#include "includes/minishell.h"


int main (int argc, char **argv)
{
    int i = -1;
    int j = -1;\

    argv++;

    while (42)
    {
        readline();
    }
    printf("builtin -->\n");
    _echo(0, argv, 0, 0);
    *argv = ft_join_free("/usr/bin/", *argv, 0);
    printf("\nFonction -->\n");
	_fct(argv, 0);

}
