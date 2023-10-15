#include "srn.h"

/**
 * srn_getpath - the user path
 * @vampcmd: command
 * Return: NULL
 */
char *srn_getpath(char *vampcmd)
{
	char *path_env, *full_vcmd, *direc;
	int i;
	struct stat st;

	for (i = 0; vampcmd[i]; i++)
	{
		if (vampcmd[i] == '/')
		{
			if (stat(vampcmd, &st) == 0)
				return (srn_duplicate(vampcmd));

			return (NULL);
		}
	}

	path_env = srn_getenv("PATH");
	if (!path_env)
		return (NULL);

	direc = strtok(path_env, ":");
	while (direc)
	{
		full_vcmd = malloc(srn_lenght(direc) + srn_lenght(vampcmd) + 2);
		if (full_vcmd)
		{
			srn_copy(full_vcmd, direc);
			srn_cat(full_vcmd, "/");
			srn_cat(full_vcmd, vampcmd);

			if (stat(full_vcmd, &st) == 0)
			{
				free(path_env);
				return (full_vcmd);
			}
			free(full_vcmd), full_vcmd = NULL;

			direc = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
