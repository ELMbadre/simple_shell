#include "shell.h"

/*
 * main - Simple Shell main function
 * @ac : Count of argument
 * @av : Arguments
 * Return : 0 Always (success)
 */
int main(int ac, char **av)
{
    char *ln = NULL;
    char **cmd = NULL;
    int stateInfo = 0 /*idx = 0*/;
    (void)ac;
    (void)av;

    while (1)
    {
        ln = readRow();
        if (ln == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (stateInfo);
        }
        /*  idx++;*/
        cmd = textSegmenter(ln);
        if (!cmd)
            continue;
    /*if (is_builtin(cmd[0]))
            handle_builtin(cmd, av, &stateInfo, idx);*/
        /*else*/
          stateInfo = carryOut(cmd, av);
    }
}
