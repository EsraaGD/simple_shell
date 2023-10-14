#include "srn.h"

char *builtins[] = {
	"exit", "env", "setenv",
	"cd", NULL
};

/**
 * the_builtin - built
 * @vampcmd: command
 * Return: None
 */
char the_builtin(char *vampcmd)
{
	(void) vampcmd;

	return (0);
}
/**
 * srn_builtin - handle the built
 * @vampcmd: command
 * @status:  an integer pointer
 * @idx: the indax
 * Return: None
 */
void srn_builtin(char **vampcmd, char **argv, int *status, int indexno)
{
	(void) argv;
	(void) indexno;

	if (srn_compare(vampcmd[0], "exit") == 0)
		exit_shell(vampcmd, status);

	else if (srn_compare(vampcmd[0], "env") == 0)
		print_env(vampcmd, status);
}

void exit_shell(char **vampcmd, int *status)
{
	srn_freearr(vampcmd);
	exit(*status);
}

void print_env(char **vampcmd, int *status)
{
	int v;

	for (v = 0; environ[v]; v++)
	{
		write(STDOUT_FILENO, environ[v], srn_lenght(environ[v]));
		write(STDOUT_FILENO, "\n", 1);
	}
	srn_freearr(vampcmd);
	(*status) = 0;
}
