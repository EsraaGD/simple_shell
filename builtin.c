#include "srn.h"

/**
 * the_builtin - built
 * @vampcmd: command
 * Return: None
 */
char the_builtin(char *vampcmd)
{
	char *builtins[] = {"exit", "env", "cd", NULL};
	int v;

	for (v = 0; builtins[v]; v++)
	{
		if (srn_compare(vampcmd, builtins[v]) == 0)
			return (1);
	}

	return (0);
}
/**
 * srn_builtin - handle the built
 * @vampcmd: command
 * @status:  an integer pointer
 * @indexno: the indax
 * @argv: array
 * Return: None
 */
void srn_builtin(char **vampcmd, char **argv, int *status, int indexno)
{
	if (srn_compare(vampcmd[0], "exit") == 0)
		exit_shell(vampcmd, argv, status, indexno);

	else if (srn_compare(vampcmd[0], "env") == 0)
		print_env(vampcmd, status);
}

/**
 * exit_shell - exits the vampire shell
 * @vampcmd: command
 * @status: int ptr
 * @indexno:indaxx
 * @argv: array
 * Return: None
 */
void exit_shell(char **vampcmd, char **argv, int *status, int indexno)
{
	int exit_ivalue = *status;
	char *index, resala[] = ": exit: ILLEGAL NUMBER: ";

	if (vampcmd[1])
	{
		if (is_positive(vampcmd[1]))
		{
			exit_ivalue = srn_strtoin(vampcmd[1]);
		}
		else
		{
			index = srn_intostr(indexno);
			write(STDERR_FILENO, argv[0], srn_lenght(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, srn_lenght(index));
			write(STDERR_FILENO, resala, srn_lenght(resala));
			write(STDERR_FILENO, vampcmd[1], srn_lenght(vampcmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			srn_freearr(vampcmd);
			return;
		}
		srn_freearr(vampcmd);
		exit(exit_ivalue);
	}
	else
	{
		srn_freearr(vampcmd);
		exit(0);
	}
}
