#include "srn.h"

/**
 * srn_2d - free the beasts
 * @srnarr: array of snars
 * Return: 0
 */

void srn_2d(char **srnarr)
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
