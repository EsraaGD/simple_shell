#include "srn.h"

void srn_parse(char *input, char **vcmd_args)
{
	char *token = strtok(input, " ");
	int v = 0;

	while (token != NULL)
	{
		vcmd_args[v] = token;
		v++;
		token = strtok(NULL, " ");
	}

	vcmd_args[v] = NULL;
}
