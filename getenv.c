#include "srn.h"

/**
 * srn_getenv - the envrument
 * @variable: string
 * Return: NULL.
 */
char *srn_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int v;

	for (v = 0; environ[v]; v++)
	{
		tmp = srn_duplicate(environ[v]);
		key = strtok(tmp, "=");
		if (srn_compare(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = srn_duplicate(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
