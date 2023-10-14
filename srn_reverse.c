#include "srn.h"

/**
 * srn_reverse - reverses a string
 * @str249:start
 * @len249:end
 * Return: NULL
 */

void srn_reverse(char *str249, int len249)
{
	char tmp;
	int begin = 0;
	int finish = len249 - 1;

	while (begin < finish)
	{
		tmp = str249[begin];
		str249[begin] = str249[finish];
		str249[finish] = tmp;
		begin++;
		finish--;
	}
}
