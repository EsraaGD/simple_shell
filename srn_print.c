#include "shell.h"

/**
 * srn_print - prints the ASR
 * Return: None
 */
void srn_print(const char *bloodsucker)	{
	write(STDOUT_FILENO, bloodsucker, strlen(bloodsucker));
}
