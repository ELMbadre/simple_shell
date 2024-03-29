#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>

#define DELIM " \t\n"

char *readRow(void);
char **textSegmenter(char *line);
int carryout(char **comd, char **argv, int idx);
extern char **environ;
char *accessenv(char *var);
char *fetchpath(char *comma);
void freearv(char **aray);

char *_itoa(int n);
void reverse_string(char *str, int len);
void displayenv(char **cmd, int *stateInfo);
void closeShell(char **cmd, char **arv, int *stateInfo, int idx);
void executebuiltin(char **cmd, char **arv, int *stateInfo, int idx);
int check_builtin(char *cmd);
int cast_atoi(char *str);
int isNonNegative(char *str);

void printerror(char *name, char *cmd, int idx);
void reverse_string(char *str, int len);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
