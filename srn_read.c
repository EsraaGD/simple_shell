#include "srn.h"

/**
 * read_input - read vampire inputs
 *
 * Return: Always 0 in success.
 */
char *read_input(void)
{
	char *steeline = NULL;
	size_t len = 0;
	ssize_t nemra;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	nemra =  getline(&steeline, &len, stdin);
	if (nemra == -1)
	{
		free(steeline);
		return (NULL);
	}
	return (steeline);
}
