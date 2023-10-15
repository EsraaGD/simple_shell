#ifndef SRN_H
#define SRN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define DELIM " \t\n"
extern char **environ;

char *srn_read(void);
char **srn_token(char *steeline);
int srn_execute(char **vampcmd, char **argv, int indexno);
void srn_freearr(char **srnarr);
char *srn_getenv(char *input);
char *srn_getpath(char *vampcmd);

char *srn_duplicate(const char *str249);
int srn_compare(char *s1249, char *s249);
int srn_lenght(char *s249);
char *srn_cat(char *dest249, char *src249);
char *srn_copy(char *dest249, char *src249);
void srn_reverse(char *str249, int len249);

char the_builtin(char *vampcmd);
void srn_builtin(char **vampcmd, char **argv, int *status, int indexno);
void exit_shell(char **vampcmd, char **argv, int *status, int indexno);
void print_env(char **vampcmd, int *status);

void srn_printerr(char *name, char *vampcmd, int indexno);
int is_positive(char *wai);
char *srn_intostr(int wai);
int srn_strtoin(char *wai);
#endif
