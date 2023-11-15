#include "strings.h"
#include <unistd.h>
/**
 * _strlen - resets *n to 98
 *
 * @s: string parameter
 *
 * Return: string length
 */

int _strlen(char *s)
{
	int x;

	for (x = 0; *s != '\0'; s++)
		++x;

	return (x);
}

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
/**
 * _putchar - entry point
 * @c: character
 * Return: 0 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, STDOUT_FILENO));
}

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

	dest[x] = '\0';
	return (dest);
}
