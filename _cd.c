#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "strings.h"
#include "env.h"
#include <string.h>

int cd_home(const char *home);
int change_ev(const char *current, char *current_directory);

/**
 * _cd - change current working directory
 * @av: arguments
 * @ac: arguments count
 * @exit_status: like the name
 * Return: 0 on success -1 on failure
 */

int _cd(char **av, int *ac, __attribute__ ((unused)) int *exit_status)
{
	const char *home = _getenv("HOME");
/*	const char *current = _getenv("PWD");*/
/*	char current_directory[1024];*/
	static char prev[1024];
	char target[1024];
	int len;

	if (*ac == 1)
	{
		len = strlen(home);
		memcpy(target, home, len);
		target[len] = '\0';
	}
	else if (_strcmp(av[1], "-") == 0)
	{

		len = strlen(prev);
		memcpy(target, prev, strlen(prev));
		target[len] = '\0';

	}
	else
	{
		len = strlen(av[1]);
		memcpy(target, av[1], strlen(av[1]));
		target[len] = '\0';
			
	}

	printf("prev before = %s\n", prev);
	printf("target now = %s\n", target);
	getcwd(prev, 1024);
	printf("prev now = %s\n", prev);
	chdir(target);


	return (0);
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
