#include "srn.h"

/**
 * srn_getpath - the path of usre
 * @vampcmd: the command
 * Return: NULL.
 */
char *srn_getpath(char *vampcmd)
{
	char *path_env, *full_vcmd, *direc;
	int v;
	struct stat rv;

	/* if vampcmd is already path */
	for (v = 0; vampcmd[v]; v++)
	{
		if (vampcmd[v] == '/')
		{
			if (stat(vampcmd, &rv) == 0) /* if path exist */
				return (srn_duplicate(vampcmd));

			return (NULL);
		}
	}
	/* if user unset path (can not get dir) */
	path_env = srn_getenv("PATH");
	if (!path_env)
		return (NULL);

	/* try handle path */
	direc = strtok(path_env, ":");
	while (direc)
	{
		/* size = len(direc) + len(vampcmd) + 2 ('/' and '\0') */
		full_vcmd = malloc(srn_lenght(direc) + strlen(vampcmd) + 2);
		if (full_vcmd)
		{
			srn_copy(full_vcmd, direc);
			srn_cat(full_vcmd, "/");
			srn_cat(full_vcmd, vampcmd);
			if (stat(full_vcmd, &rv) == 0)
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
