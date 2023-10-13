#include "srn.h"

/**
 * srn_getpath - the path of usre
 * @command: the command
 * Return: NULL.
 */
char *srn_getpath(char *vampcmd)
{
	char *path_env, *full_cmd, *direc;
	struct stat rv;

	path_env = srn_getenv("PATH");

	direc = strtok(path_env, ":");
	while (direc)
	{
		full_cmd = malloc(srn_lenght(direc) + strlen(vampcmd) + 2);
		if (full_cmd)
		{
			srn_copy(full_cmd, direc);
			srn_cat(full_cmd, "/");
			srn_cat(full_cmd, vampcmd);
			if (stat(full_cmd, &rv) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			direc = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
