#include "srn.h"

/**
 * main - prints the enviro
 * @ac: count of arguments
 * @argv: arguments
 * Return: none
 */

int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		line = srn_read();
		if (line == NULL) /*CTRL+D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = srn_token(line);
		if (!command)
			continue;

		if (srn_compare(command[0], "exit") == 0)
		{
			srn_freearr(command);
			exit(status);
		}

		status = srn_execute(command, argv);
	}

}
