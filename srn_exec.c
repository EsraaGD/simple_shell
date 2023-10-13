#include "srn.h"

/**
 * srn_execute - function to execute vampire command
 * @vampcmd: command
 * @argv: argument
 * Return: command
 */

int srn_execute(char **vampcmd, char **argv)
{
	char *full_cmd;
	pid_t baby;
	int status;

	 full_cmd = srn_getpath(vampcmd[0]);
	 if (!full_cmd)
	 {
		 printerror();
		 srn_freearr(vampcmd);
		 return (127);
	 }
	if (strchr(vampcmd[0], '/') == NULL)
	{
		fprintf(stderr, "%s: %d: %s: Not found\n", argv[0], 1, vampcmd[0]);
		srn_freearr(vampcmd);
		status = 127;
		return (status);
	}

	baby = fork();
	if (baby == 0)
	{
		if (execve(vampcmd[0], vampcmd, environ) == -1)
		{
			fprintf(stderr, "%s: %d: %s: Not found\n", argv[0], 1, vampcmd[0]);
			free(full_cmd), full_cmd = NULL;
			srn_freearr(vampcmd);
		}
	}

	else
		{
			waitpid(baby, &status, 0);
			srn_freearr(vampcmd);
			free(full_cmd), full_cmd = NULL;
		}

	return (WEXITSTATUS(status));
}
