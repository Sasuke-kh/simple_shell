#include <unistd.h>
#include "main.h"
/**
 * main - entry point
 *
 * Description: print _putchar
 *
 * Return: 0 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
