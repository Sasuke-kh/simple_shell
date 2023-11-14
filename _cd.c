#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"
int cd_home(const char *home);
int change_ev(const char *current, char *current_directory, const char *prev);

/**
 * _cd - change current working directory
 * @av: arguments
 * @ac: arguments count
 * Return: 0 on success -1 on failure
 */

int _cd(char **av, int *ac)
{
	const char *home = _getenv("HOME");
	const char *prev = _getenv("OLDPWD");
	const char *current = _getenv("PWD");
	char current_directory[1024];

	if (*ac == 1)
	{
		if (cd_home(home) == 0)
		{
			if (change_ev(current, current_directory, prev) == 0)
				return (0);
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (strcmp(av[1], "-") == 0)
	{
		if (chdir(prev) == 0)
		{
			if (change_ev(current, current_directory, prev) == 0)
				return (0);
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (strcmp(av[1], "..") == 0)
	{
		if (chdir("..") == 0)
		{
			if (change_ev(current, current_directory, prev) == 0)
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
			if (change_ev(current, current_directory, prev) == 0)
				return (0);
			else
				return (-1);
		}
		else
			return (1);
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
 * @prev: previos dir
 * Return: 0 on success -1 on failure
 */

int change_ev(const char *current, char *current_directory, const char *prev)
{
	if (_setenv(prev, current, 1) == 0)
	{
		if (getcwd(current_directory, 1024) != NULL)
		{
			if (_setenv(current, current_directory, 1) == 0)
			{
				printf("\n\n%s\n\n", prev);
				return (0);
			}
			else
				return (-1);
		}
		else
			return (-1);
	}
	else
		return (-1);
}
