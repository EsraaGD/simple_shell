#include "srn.h"

/**
 * read_input - read suer inputs
 * Return: Always 0 in success.
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		srn_print("$ ");
	n =  getline(&line, &len, stdin);
	if (n == -1)
	{	free(line);
		return (NULL);
	}
	return (line);
}
