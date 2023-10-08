#include "srn.h"

/*
 * main (int) - prints the enviro
 * @srnargc: count of arguments
 * @argv: arguments
 * Return: None
 */

int main(int srnargc, char **argv)
{
	char *steeline = NULL;
	int status = 0;
	(void) srnargc;
	(void) argv;

	while (1)
	{
		steeline = srn_read();
		if (steeline == NULL) /* end of file ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		printf("%s", steeline);
		free(steeline);
	}
}
