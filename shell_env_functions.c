#include "command.h"
#include "env.h"
#include <stdio.h>
#include "strings.h"

/**
 * shell_env - doc
 * @av: args
 * @ac: args count
 * @exit_status: exit_status
 * Return: doc
 */

int shell_env(__attribute__ ((unused)) char **av, int *ac,
							 __attribute__ ((unused)) int *exit_status)
{
	if (*ac == 1)
	{
		print_env();
		return (0);
	}
	else
	{
		print_error("Wrong number of arguments");
		print_str("\n");
		return (-1);
	}

}

/**
 * shell_setenv - doc
 * @av: args
 * @ac: args count
 * @exit_status: exit_status
 * Return: doc
 */

int shell_setenv(char **av, int *ac, __attribute__ ((unused)) int *exit_status)
{
	if (*ac != 3)
	{
		print_error("Error wrong number of arguments");
		print_error("\n");
		return (-1);
	}
	else
	{
		if (_setenv(av[1], av[2], 1))
		{
			print_error("Error Can't unset env");
				print_error("\n");
			return (-2);
		}
	}
	return (0);
}

/**
 * shell_unsetenv - doc
 * @av: args
 * @ac: args count
 * @exit_status: exit_status
 * Return: doc
 */

int shell_unsetenv(char **av, int *ac,
				 __attribute__ ((unused)) int *exit_status)
{
	if (*ac != 2)
	{
		print_error("Error wrong number of arguments");
		print_error("\n");
		return (-1);
	}
	else
	{
		if (_unsetenv(av[1]))
		{
			print_error("Error Can't unset env");
			print_error("\n");
			return (-2);
		}
	}
	return (0);
}
