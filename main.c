#include "srn.h"

/*
 * main (int) - prints the enviro
 * @srnargc: count of arguments
 * @argv: arguments
 * Return: None
 */

int main(int argc, char **argv)
{
	char *steeline = NULL, **vampcmd = NULL;
	int status = 0;
	(void) argc;

	while (1)
	{
		steeline = read_input();
		if (steeline == NULL) /* end of file ctrl + D */
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			return (status);

		}

		vampcmd = tokenizer(steeline);
		if (!vampcmd)
			continue;

		status =srn_exec(vampcmd, argv);
		if (status == -1)
		{
			perror("srn_exec");
			return (1);
		}
		free(vampcmd);

	}
	return (0);
}

