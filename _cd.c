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
	static char prev[1024];
	char target[1024];

	if (*ac == 1)
		strcpy(target, home);
	else if (_strcmp(av[1], "-") == 0)
		strcpy(target, prev);
	else
		strcpy(target, av[1]);
			

	getcwd(prev, 1024);
	chdir(target);


	return (0);
}

