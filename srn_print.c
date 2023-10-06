#include "srn.h"

/**
 * srn_print - prints the ASR
 *
 * @bloodsucker: Message to output to vampire
 *
 * Return: None
 */

void srn_print(const char *bloodsucker)
{
	write(STDOUT_FILENO, bloodsucker, strlen(bloodsucker));
}
