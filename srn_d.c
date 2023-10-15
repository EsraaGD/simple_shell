#include "srn.h"

int srn_strtoin(char *wai)
{
	int v, nemra = 0;

	for (v = 0; wai[v]; v++)
	{
		nemra *= 10;
		nemra += (wai[v] - '0');
	}
	return (nemra);
}

int is_positive(char *wai)
{
	int v;

	if (!wai)
	return (0);
	for (v = 0; wai[v]; v++)
	{
		if (wai[v] < '0' || wai[v] > '9')
			return (0);
	}
	return (1);
}
