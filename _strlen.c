#include "main.h"

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
