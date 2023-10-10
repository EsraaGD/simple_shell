#include "srn.h"

/**
 * srn_exec - execte command inputted by vamps
 * @vampcmd: command by vamp
 * @argv: arguments suishg
 *
 * Return: false or -1
 */

int srn_exec(char **vampcmd, char **argv[])

{
	pid_t child = fork();
	int status;

	if (child == 0)
	{
		if (execve(vampcmd[0], vampcmd, environ) == -1)
		{
			perror(argv[0]);
			srn_2d(vampcmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		srn_2d(vampcmd);
	}
	return (WEXITSTATUS(status));
}
