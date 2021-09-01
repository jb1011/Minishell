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
    char    n;
    char    apostrophe;
    char    guillemet;
    char    stringadefine[] = "\'\"$";
    char    *object;

    s.i = -1;
    apostrophe = 0;
    guillemet = 0;
    s.stra = ft_strdup("");
    n = 1;
    int i = 0;
    printf("Phase %d\n", ++i);
    ++opts;
    if (!ft_memcmp(*opts, "-n", 3) && ++opts)
        n = 0;
    if (!opts)
        return (0);
    printf("Phase %d\n", ++i);
    object = *opts;
    // printf("Object === %s\n", object);
    //printf("%s\n", object);
    while (object[++s.i])
    {
    // printf("Phase %d\n", ++i);
       if (object[s.i] == '\"' && !apostrophe)
        {
            printf("Phase guillemet\n" );
            if (!guillemet)
                guillemet = 1;
            else
                guillemet = 0;
        }
        else if (object[s.i] == '\'' && !guillemet) //Booleen pour savoir si on compte les charatere speciaux , ' == pas de consideration pour carateres speciaux
        {
            printf("Phase apostrophe\n");
            if (!apostrophe)
                apostrophe = 1;
            else
                apostrophe = 0;
        }
        else if (apostrophe) // Du coup on print sans reflechir
        {
            printf("Phase apostrophe et string\n");
            s.k = s.i + 1;// si on tombe direct sur le ' ca compte pas
            while (object[++s.i] && object[s.i] != '\'')
                ;
            if (!object[s.i])
                return (ft_err_msg("ERREUR DANS LE PARSING !!!!!!! pour dquotes"));
            s.stra = ft_join_free(s.stra, extractstr(&object[s.k - 1], "\'"), 3);
            s.i--;
        }
        else if (object[s.i] == '$')
        {
            printf("Phase dollar\n");
            s.k = 0;
            if (object[s.i + 1] == '$' && ++s.k)
            {
                s.stra = ft_join_free(s.stra, "$$", 1);
            }
            else if (!object[s.i + 1])
                s.stra = ft_join_free(s.stra, "$", 1);
            // Rajouter exception guillemets
            else
            {
                s.k = s.i + 1;
                while (!ft_strchr(stringadefine, object[++s.i]))
                    ;
                s.strb = extractstr(&object[s.k], stringadefine);
                s.stra = ft_join_free(s.stra, getenv(s.strb), 3);
                free(s.strb);
                s.i--;
            }
        }
        else //string normal
        {
            s.k = s.i;
            while (!ft_strchr(stringadefine, object[++s.i]))
                ;
            s.strb = extractstr(&object[s.k], stringadefine);
            // printf("normal avant free\n");
            s.stra = ft_join_free(s.stra,s.strb,  3);
            // printf("normal apres free\n");
            s.i--;
        }
    }
    if (n)
        s.stra = ft_join_free(s.stra, "\n", 1);
    if (!redirection_or_pipes || ft_strlen(redirection_or_pipes) < place)
        ft_putstr(s.stra);
    free(s.stra);
}
