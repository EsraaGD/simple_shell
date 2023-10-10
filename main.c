#include "srn.h"

/*
 * main (int) - prints the enviro
 * @srnargc: count of arguments
 * @argv: arguments
 * Return: None
 */

int main(int srnargc, char **argv)
{
	char *steeline = NULL, **vampcmd = NULL;
	int status = 0;
	(void) srnargc;

	while (1)
	{
		steeline = srn_read();
		if (steeline == NULL) /* end of file ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				srn_print((char *)"\n");
			return (status);
		}

		free(vampcmd);
		vampcmd = tokenizer(steeline);
		if (!vampcmd)
			continue;

		status = srn_exec(vampcmd, argv);
	}
}
