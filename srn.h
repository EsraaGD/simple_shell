#ifndef SRN_H
#define SRN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *read_input(void);
char **tokenizer(char *steeline);
int srn_exec(char **vampcmd, char **argv);
void freearray(char **srnarr);

char *_strdup(const char *str);

#endif
