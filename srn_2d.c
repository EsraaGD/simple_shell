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
