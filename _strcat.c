#include "main.h"

/**
 * _strcat - resets *n to 98
 *
 * @dest: type char
 * @src: char type
 *
 * Return: nu * sign
 */

char *_strcat(char *dest, char *src)
{
	int x, x2;

	x = 0;

	while (dest[x])
		x++;

	for (x2 = 0; src[x2] ; x2++)

		dest[x++] = src[x2];

	return (dest);
}
