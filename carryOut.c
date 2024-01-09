#include "shell.h"

int carryOut(char **comd,char **argv)
{
   /* char *full_cmd;*/
    pid_t child;
    int statusFlag;

    child = fork();
    if(child == 0)
    {
       if (execve(comd[0], comd, environ) == -1)
        {
           perror(argv[0]);
            freearv(comd);
            exit(0);
        }
    }
    else
    {
        waitpid(child,&statusFlag,0);
       freearv(comd);
    }
    return (WEXITSTATUS(statusFlag));
}