#include "srn.h"

/**
 * **srn_token - tokenizer
 * @steeline: line
 * Return: Tokenized string
 */

char **srn_token(char *steeline)
{
	char *tokensep = NULL, *tmp = NULL;
	char **vampcmd = NULL;
	int tokcount = 0, v = 0;

	if (!steeline)
		return (NULL);
	tmp = srn_duplicate(steeline);
	tokensep = strtok(tmp, DELIM);
	if (tokensep == NULL)
	{
		free(steeline), steeline = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (tokensep)
	{
		tokcount++;
		tokensep = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	vampcmd = malloc(sizeof(char *) * (tokcount + 1));
	if (!vampcmd)
	{
		free(steeline), steeline = NULL;
		return (NULL);
	}
	tokensep = strtok(steeline, DELIM);
	while (tokensep)
	{
		vampcmd[v] = srn_duplicate(tokensep);
		tokensep = strtok(NULL, DELIM);
		v++;
	}
	free(steeline), steeline = NULL;
	vampcmd[v] = NULL;
	return (vampcmd);
}
