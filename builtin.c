#include "srn.h"

/**
 * the_builtin - built
 * @vampcmd: command
 * Return: None.
 */
char the_builrin(cahr *vampcmd)
{
	char *builtins[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
/**
 * srn_builtin - handle the built
 * @vampcmd: command
 * @argv: argument
 * @status:  an integer pointer
 * @idx: the indax
 * Return: 0.
 */
void srn_builtin(char **vampcmd, char **argv, int *status, int indexno)
{
	(void) arg;
	(void) indexno;

	if (srn_compare(vampcmd[0], "exit") == 0)
		exit_shell(vampcmd, status);

	else if (srn_compare(vampcmd[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - exit shell
 * @vampcmd: the command
 * @status:  an integer pointer
 * Return: None
 */
void exit_shell(char **vampcmd, int *status)
{
	srn_freearr(vampcmd);
	exit(*status);
}

/**
 * print_env - print the envaurment
 * @vampcmd: command
 * @status: an integer pointer
 * Return: None
 */
void print_env(char **vampcmd, int *status)
{
	int v;

	for (v = 0; environ[v]; v++)
	{
		write(STDOUT_FILENO, environ[v], srn_lenght(environ[v]));
		write(STDOUT_FILENO, "\n", 1);
	}
	srn_freearr(vampcmd);
	status = 0;
}
