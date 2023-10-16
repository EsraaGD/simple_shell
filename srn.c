#include "srn.h"

/**
 * main - prints the enviro
 * @ac: count of arguments
 * @argv: arguments
 * Return: none
 */

int main(int ac, char **argv)
{
	char *line = NULL, **vampcmd = NULL;
	int status = 0, indexno = 0;
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
		indexno++;
		vampcmd = srn_token(line);
		if (!vampcmd)
			continue;

		if (srn_compare(vampcmd[0], "exit") == 0)
		{
			srn_freearr(vampcmd);
			exit_shell(vampcmd, argv, &status, indexno);
		}

		if (the_builtin(vampcmd[0]))
			srn_builtin(vampcmd, argv, &status, indexno);
		else
		status = srn_execute(vampcmd, argv, indexno);
	}

}
