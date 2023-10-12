#include "srn.h"

/**
 * srn_lenght - find length of string
 * @s: input string
 * Return: the length
 */

int srn_lenght(char *s249)
{
	int tall = 0;

	while (s249[tall])
		tall++;
	return (tall);
}

/**
 * srn_cat - links two string
 * @dest249: destniation string
 * @src249: source string
 * Return: pointer of dest
 */

char *srn_cat(char *dest249, char *src249)

{
	char *ikea = dest249;

	while (ikea)
		ikea++;
	while (*src249)
	{
		*ikea = *src249;
		ikea++;
		src249++;
	}
	*ikea = '\0';
	return (dest249);
}

/**
 * srn_duplicate - duplicates given string
 * @str249: said string
 * Return: ptr
 */

char *srn_duplicate(const char *str249)
{
	char *ptr249;
	int ikea, len = 0;

	if (str249 == NULL)
		return (NULL);
	while (str249[len])
		len++;
	ptr249 = malloc(sizeof(char) * (len + 1));
	if (ptr249 == NULL)
		return (NULL);
	for (ikea = 0; ikea <= len; ikea++)
		ptr249[ikea] = str249[ikea];
	return (ptr249);
}
/**
 * srn_compare - compare 2 strings
 * @s1249: first string
 * @s249: seconed string
 * Return: 0, -, +
 */

int srn_compare(char *s1249, char *s249)
{
	int cmpvar;

	cmpvar = (int) *s1249 - (int) *s249;
	while (*s1249)
	{
		if (*s1249 != *s249)
			break;
		s1249++;
		s249++;
		cmpvar = (int) * s1249 - (int) *s249;
	}
	return (cmpvar);
}

/**
 * srn_copy - copy string
 * @dest249: destnition buffer
 * @src249: source string
 * Return: pointer
 */

char *srn_copy(char *dest249, char *src249)
{
	int ikea = 0;

	while (src249[ikea])
	{
		dest249[ikea] = src249[ikea];
		ikea++;
	}
	dest249[ikea] = '\0';
	return (dest249);
}
