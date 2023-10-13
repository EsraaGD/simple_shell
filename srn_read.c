#include "srn.h"

/**
 * *srn_read - read vampire input
 * Return: 0
 */

char *srn_read(void)
{
	char *steeline = NULL;
	size_t lenn = 0;
	int nemra;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	nemra = getline(&steeline, &lenn, stdin);

	if (nemra == -1)
	{
		free(steeline);
		return (NULL);
	}

	return (steeline);
}
