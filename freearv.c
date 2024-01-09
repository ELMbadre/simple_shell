#include "shell.h"

void freearv(char **aray)
{
    int n;
    if (!aray)
        return;
    for (n = 0 ;aray[n]; n++)
    {
        free(aray[n]);
        aray[n] = NULL;
    }
        free(aray), aray = NULL;
}