#include "srn.h"

/*
 * main - print the environment
 * @argc: count of arguments
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
			if (isatty(STDIN_FILENO))
				srn_print((char *)'\n');
			return (status);
		}

		free(line);
	}
}
