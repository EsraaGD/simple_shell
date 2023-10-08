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

#define DELIMITER " \t\n"
void srn_print(const char *bloodsucker);
void srn_prompt(void);
char *srn_read(void);
char **tokenizer(char *steeline);

char *_strdup(const char *str);

#endif
