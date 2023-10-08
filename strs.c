#include "srn.h"

/**
 * _strdup - function allocates memory for the duplicate string
 * @str: char pointer to copy
 * Return: a new char pointe
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, steelen = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		steelen++;
		str++;
	}
	str = str - steelen;
	ptr = malloc(sizeof(char) * (steelen + 1));
	if (ptr == NULL)
		return (0);
	for (i = 0; i <= steelen; i++)
		ptr[i] = str[i];

	return (ptr);
}
