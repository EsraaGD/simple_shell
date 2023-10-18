#include "srn.h"

/**
 * print_env - print the currect environment
 * Retrun: None
 */
void print_env (char **vampcmd, int *status)
{
	extern char **environ;
	int v;
	(void) vampcmd;
	(void) status;

	for (v = 0; environ[v]  != NULL; v++)
	{
		write(1, environ[v], strlen(environ[v]));
		write(1, "\n", 1);
	}
	free(environ);
}
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
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;

	}
	return (NULL);
}
