#include "srn.h"

/**
 * *srn_getenv - the envrument
 * @input: string
 * Return: NULL
 */

char *srn_getenv(char *input)
{
	int v;
	char *tmp, *ikey, *ivalue, *env;

	for (v = 0; environ[v]; v++)
	{
		tmp = srn_duplicate(environ[v]);
		ikey = strtok(tmp, "=");

		if (srn_compare(ikey, input) == 0)
		{
			ivalue = strtok(NULL, "\n");
			free(tmp);
			env = srn_duplicate(ivalue);
			return (env);
		}
		free(tmp), tmp = NULL;

	}
	return (NULL);
}
