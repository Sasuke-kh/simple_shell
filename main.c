#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <sys/types.h>
#include <sys/wait.h>
#include "command.h"
#include "main.h"
#include "strings.h"
#include "helpers.h"

int sh_script(char **argv, char **env);
int sh_non_interactive(char **env);
int sh_interactive(char **env);
void free_av_memory(char **av, int ac);

int main(int argc, char **argv, char **env)
{

	if (argc > 1)
	{
		sh_script(argv, env);
	}
	else if (argc == 1)
	{
		if (isatty(0))
		{
			sh_interactive(env);
		}
		else
		{
			sh_non_interactive(env);
		}
	}

	return (0);
}

int sh_script(char **argv, char **env)
{
	int ac;
	char **av = NULL;
	list_t *paths_head = NULL;
	int done = 0;
	int fd;

	fd  = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Can't open %s\n", argv[1]);
		return (-4);
	}

	av = (char **)malloc(100 * sizeof(char *));  /*Is 100 enough ? */

	while (!(get_command_from_file(fd, av, &ac)))
	{
		if (get_PATH(env, &paths_head))
		{
			printf("Error!! Can't get path\n");
		}
		else
		{
			if (is_found_and_excecutable(av, paths_head))
			{
				printf("Error!! Command not found\n");
			}
			else
			{
				if (fork_and_execve(av, env))
				{
					printf("Error!! Commmand can't get executed\n");
				}
				else
				{
					done = 1;
				}
			}
			if (!done)
			{
				if (is_built_in_commnad(av))
				{
					printf("IS NOT A BUILT IN COMMAND\n");
					printf("hsh : not found\n");
				}
			}
		}
		free_av_memory(av, ac);
	}
	free(av);
	free_list(paths_head);
	return (0);
}

int sh_non_interactive(char **env)
{
	int ac;
	char **av = NULL;
	list_t *paths_head = NULL;
	int c_s = 0;
	int done = 0;

	av = (char **)malloc(100 * sizeof(char *));  /*Is 100 enough?*/
	c_s = get_command(av, &ac);
	if (c_s == -1)
	{
		printf("Error!! Can't get command\n");
	}
	else if (c_s == -2)		/* EOF */
	{

	}
	else
	{
		if (get_PATH(env, &paths_head))
		{
			printf("Error!! Can't get path\n");
		}
		else
		{
			if (is_found_and_excecutable(av, paths_head))
			{
				printf("Error!! Command not found\n");
			}
			else
			{
				if (fork_and_execve(av, env))
				{
					printf("Error!! Commmand can't get executed\n");
				}
				else
				{
					done = 1;
				}
			}
			if (!done)
			{
				if (is_built_in_commnad(av))
				{
					printf("IS NOT A BUILT IN COMMAND\n");
					printf("hsh : not found\n");
				}
			}
		}
		free_av_memory(av, ac);
	}
	free(av);
	free_list(paths_head);
	return (0);
}
int sh_interactive(char **env)
{
	int status = 1;
	int ac;
	char **av = NULL;
	list_t *paths_head = NULL;
	int c_s = 0;

	av = (char **)malloc(100 * sizeof(char *));  /*Is 100 enough ?*/
	while (status)
	{
		printf("($) ");
		fflush(stdout);
		c_s = get_command(av, &ac);
		if (c_s == -1)
		{
			printf("Error!! Can't get command\n");
			continue;
		}
		else if (c_s == -2)			/* EOF */
		{
			break;
		}

		if (get_PATH(env, &paths_head))
		{
			printf("Error!! Can't get path\n");
			continue;
		}
		if (is_found_and_excecutable(av, paths_head))
		{
			printf("Error!! Command not found\n");
		}
		else
		{
			if (fork_and_execve(av, env))
			{
				printf("Error!! Commmand can't get executed\n");
			}
			continue;
		}

		if (is_built_in_commnad(av))
		{
			printf("IS NOT A BUILT IN COMMAND\n");
			printf("hsh : not found\n");
		}
		free_av_memory(av, ac);
	}
	free(av);
	free_list(paths_head);
	return (0);
}


void free_av_memory(char **av, int ac)
{
	int i = 0;

	for (i = 0; i < ac; i++)
	{
		free(av[i]);
	}
}
