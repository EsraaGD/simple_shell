#include "srn.h"

/**
 * srn_freearr - free the beasts
 * @srnarr: array of snars
 * Return: 0
 */

void srn_freearr(char **srnarr)
{
	int iyes;

	if (!srnarr)
		return;

	for (iyes = 0; srnarr[iyes]; iyes++)
	{
		free(srnarr[iyes]);
		srnarr[iyes] = NULL;
	}

	free(srnarr), srnarr = NULL;
}

/**
 * srn_printerr - prints error message
 * @name: name of command Eg:hello
 * @command:command to be executd
 * @indexno: number of command
 * Return: NULL
 */

void srn_printerr(char *name, char *command, int indexno)
{
	char *index, resala[] = ": not found\n";

	index = srn_intostr(indexno);

	write(STDERR_FILENO, name, srn_lenght(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, srn_lenght(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, srn_lenght(command));
	write(STDERR_FILENO, resala, srn_lenght(resala));

	free(index);
}

/**
 * srn_intostr - function to change integer to string
 * @wai: variable
 * Return: NULL
 */

char *srn_intostr(int wai)
{
	char buffy[50];
	int v = 0;

	if (wai == 0)
		buffy[v++] = '0';

	else
	{
		while (wai > 0)
		{
			buffy[v++] = (wai % 10) + '0';
			wai /= 10;
		}
	}
	buffy[v] = '\0';
	srn_reverse(buffy, v);

	return (srn_duplicate(buffy));
}
