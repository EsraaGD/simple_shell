#include "srn.h"

/**
 * read_input - read suer inputs
 * Return: Always 0 in success.
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t i;

	write(STDOUT_FILENO, "$ ", 2);
	i = getline(&line, &len, stdin);
	if (i == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
