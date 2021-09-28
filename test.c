#include "includes/minishell.h"


int main (int argc, char **argv)
{
    char *str = ft_strdup(argv[1]);
    changeline(0,&str);
    printf("%s\n", str);
}
