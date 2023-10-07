#include "srn.h"

/**
 * read_input - read suer inputs
 * Return: Always 0 in success.
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nemra;

	if (isatty(STDIN_FILENO))
	{
		srn_print("$ ");
	}
	nemra =  getline(&line, &len, stdin);
	if (nemra == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
