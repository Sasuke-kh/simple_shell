#include "strings.h"
#include <unistd.h>

/**
 * print_str - print string
 * @str: givan string
 * Return: void
 */

void print_str(char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count ++)
	{
		_putchar(str[count]);
	}
}

/**
 * main - entry point
 *
 * Description: print _putchar
 *
 * Return: 0 (success)
 */
int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * print_error - print string
 * @str: givan string
 * Return: void
 */

void print_error(char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count ++)
	{
		_puterror(str[count]);
	}
}
