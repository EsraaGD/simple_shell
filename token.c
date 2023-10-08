#include "srn.h"

/*
 * tonkenize - gdgdv
 * Return: hs
 */
char **tokenizer(char *steeline)
{
	char *token = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (steeline)
	{
		return (NULL);
	}
	token = (char  *)_strdup(steeline);
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

	command = (char **)malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		return (NULL);
	} 
	token = (char *)_strdup(steeline);
	if (!token)
	{
		free(command);
		return (NULL);
	}

	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}
	/* Free the memory allocated by steeline */
	free(token);
	command[i] = NULL;
	return (command);
}
