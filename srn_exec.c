#include "srn.h"

/**
 * srn_exec - execte command inputted by vamps
 * @vampcmd: command by vamp
 * @argv: arguments suishg
 *
 * Return: false or -1
 */

int srn_exec(char **vampcmd, char **argv)

{
	pid_t child;
	int status;
	(void) argv;

	child = fork();
	if (child == -1)
	{
		return (-1);
	}
	else
		if (child == 0)
	{
		if (execve(vampcmd[0], vampcmd, environ) == -1)
			_exit(1);
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (WEXITSTATUS(status));
}
