#include "srn.h"

/*
 * tonkenize - gdgdv
 * Return: hs
 */
char **tokenizer(char *steeline)
{
	char *token = NULL, *tmp = NULL;
	char **vampcmd = NULL;
	int cpt = 0, i = 0;

	if (!steeline)
		return (NULL);
	tmp = _strdup(steeline);
	token = strtok(tmp, DELIM);
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	/* Free the memory allocated by _strdup() */
	free(tmp), tmp = NULL;

	vampcmd= malloc(sizeof(char *) * (cpt + 1));
	if (!vampcmd)
	{
		free(steeline);
		return (NULL);
	}
	token = strtok(steeline, DELIM);
	while (token)
	{
		vampcmd[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	
	/* Free the memory allocated by steeline */
	free(steeline), steeline = NULL;

	vampcmd[i] = NULL;
	return vampcmd;
}
