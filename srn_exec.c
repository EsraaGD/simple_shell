#include "srn.h"

/**
 * srn_execute - function to execute vampire command
 * @vampcmd: command
 * @argv: argument
 * @indexno: number to specify number of command
 * Return: command
 */

int srn_execute(char **vampcmd, char **argv, int indexno)
{
	char *full_vcmd;
	pid_t baby;
	int status;

	full_vcmd = srn_getpath(vampcmd[0]);
	if (!full_vcmd)
	{
	srn_printerr(vampcmd[0], argv[0], indexno);
		srn_freearr(vampcmd);
		return (127);
	}
	baby = fork();
	if (baby == 0)
	{
		if (execve(full_vcmd, vampcmd, environ) == -1)
		{
			free(full_vcmd), full_vcmd = NULL;
			srn_freearr(vampcmd);
		}
	}

	else
	{
		waitpid(baby, &status, 0);
		srn_freearr(vampcmd);
		free(full_vcmd), full_vcmd = NULL;
	}
	return (WEXITSTATUS(status));
}
