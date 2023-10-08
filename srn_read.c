#include "srn.h"

/**
 * srn_read - read vampire inputs
 *
 * Return: Always 0 in success.
 */
char *srn_read(void)
{
	char *steeline = NULL;

	size_t steelen = 0;

	ssize_t nemra;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	nemra =  getline(&steeline, &steelen, stdin);

	if (nemra == -1)
	{
		free(steeline);
		return (NULL);
	}
	return (steeline);
}
