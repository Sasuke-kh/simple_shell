#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include "strings.h"
#include "env.h"
int cd_home(const char *home);
int change_ev(const char *current, char *current_directory);

/**
 * _cd - change current working directory
 * @av: arguments
 * @ac: arguments count
 * Return: 0 on success -1 on failure
 */

int _cd(char **av, int *ac)
{
	const char *home = _getenv("HOME");
	const char *current = _getenv("PWD");
	static char *prev;
	char current_directory[1024];

	/*if (prev == NULL)
		prev = (char *)current;*/
	if (*ac == 1)
	{
		if (cd_home(home) == 0)
		{
			prev = (char *)current;
			if (change_ev(current, current_directory) == 0)
				return (0);
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (_strcmp(av[1], "-") == 0)
	{
		if (chdir(prev) == 0)
		{
			prev = current_directory;
			if (change_ev(current, current_directory) == 0)
			{
				print_str(current_directory);
				print_str("\n");
				return (0);
			}
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (_strcmp(av[1], "..") == 0)
	{
		if (chdir("..") == 0)
		{
			prev = (char *)current;
			if (change_ev(current, current_directory) == 0)
				return (0);
			else
				return (-1);
		}
		else
			return (-1);
	}
	else
	{
		if (chdir(av[1]) == 0)
		{
			prev = (char *)current;
			if (change_ev(current, current_directory) == 0)
				return (0);
			else
				return (-1);
		}
		else
		{
			print_error("hsh: 2: cd: can't cd to ");
			print_error(av[1]);
			print_str("\n");
			return (-1);
		}
	}
	return (-1);
}

/**
 * cd_home - change to home dir
 * @home: pointer to home ev
 * Return: 0 on success -1 on failure
 */

int cd_home(const char *home)
{
	if (home != NULL)
	{
		if (chdir(home) == 0)
			return (0);
		else
			return (-1);
	}
	else
		return (-1);
}

/**
 * change_ev - edit the EV
 * @current: current dir
 * @current_directory: like the name ;)
 * Return: 0 on success -1 on failure
 */

int change_ev(const char *current, char *current_directory)
{
		if (getcwd(current_directory, 1024) != NULL)
		{
			if (_setenv(current, current_directory, 1) == 0)
			{
				return (0);
			}
			else
				return (-1);
		}
		else
			return (-1);
}
