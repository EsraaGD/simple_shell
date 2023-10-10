#include "srn.h"

/*
 * tonkenize - gdgdv
 * Return: hs
 */
char **tokenizer(char *steeline)
{
	char *token = NULL;
	char **vampcmd = NULL;
	int cpt = 0, i = 0;

	if (steeline)
	{
		return (NULL);
	}
	token = _strdup(steeline);
	if (!token)
	{
		return (NULL);
	}

	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIMITER);
	}
	/* Free the memory allocated by _strdup() */
	free(token);

	vampcmd= (char **)malloc(sizeof(char *) * (cpt + 1));
	if (!vampcmd)
	{
		return (NULL);
	} 
	token = _strdup(steeline);
	if (!token)
	{
		free(vampcmd);
		return (NULL);
	}

	while (token)
	{
		vampcmd[i] = _strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}
	/* Free the memory allocated by steeline */
	free(token);

	vampcmd[i] = NULL;
	return vampcmd;
}
