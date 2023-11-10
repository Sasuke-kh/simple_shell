#include "main.h"

/**
 * *_strcpy - copies src
 *
 * @dest: parameter
 * @src: parameter
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int y = -1;

	do {
		y++;
		dest[y] = src[y];
	} while (src[y] != '\0');

	return (dest);
}
