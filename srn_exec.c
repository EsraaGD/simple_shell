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

	child = fork();
	if (child == 0)
	{
		if (execve(vampcmd[0], vampcmd, environ) == -1)
		{
			perror(argv[0]);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (WEXITSTATUS(status));
}
