#include "srn.h"

/**
 * srn_2darr - frees 2d array frm vampires
 * @vampsarray: arrays to be freed from vampires
 * @hoomans (list): input
 * Return: none
 */

void srn_2darr(char **vampsarray)

{
	int hoomans;

	if (!vampsarray)
		return;

	for (hoomans = 0; vampsarray[hoomans]; hoomans++)

	{
		free(vampsarray[hoomans]);
		vampsarray[hoomans] = NULL;
	}

	free(vampsarray), vampsarray = NULL;
}
