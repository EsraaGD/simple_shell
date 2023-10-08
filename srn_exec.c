#include "srn.h"

/**
 * srn_execute - executes vamp bite
 * *
 * Return: 0
 */

int srn_execute(char *command, char **argv)

{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command == -1))
		{
			perror(argv[0]);
			srn_2darr(command);
		}

		srn_2darr(command);
	}
}
