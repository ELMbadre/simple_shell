#include "shell.h"

char *readRow(void)
{
        char *ln = NULL;
        size_t len = 0;
        ssize_t i;

        if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "$ ", 2);
        i = getline(&ln, &len, stdin);
        if (i == -1)
        {
                free(ln);
                return (NULL);
        }
        return (ln); 
}