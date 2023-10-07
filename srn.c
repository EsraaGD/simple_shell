#include "srn.h"

/**
 * main - print the environment
 * @ragc: count of arguments
 * @argv: arguments
 * Return: Alway 0.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	int status = 0;
	(void) argc;
	(void) argv;

	while (1)
	{
		line = read_input();
		if (line == NULL) /* end of file ctrl + D */
		{
			if (isatty(SIDIN_FILENO))
				write(STDOUT_FILENO, '\n', 1);
			return (status);
		}

		srn_print("%s", line);
		free(line);

	}
return (0);
}
