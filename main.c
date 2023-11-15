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
#include "memory_manager.h"
#include <signal.h>
#include "env.h"
#include <fcntl.h>

extern char **environ;

typedef void (*sighandler_t)(int);

int sh_handler(char **env, int fd, int is_ineractive);
void exit_handler(int i)
{
	if (i == SIGINT)
	{
		free_manager(NULL);
		exit(0);
	}
}
int main(int argc, char **argv)
{
	sighandler_t sig;
	int is_interactive = 0;
	int fd;
	int exit_status;
	sig = signal(SIGINT, exit_handler);
	if (sig == SIG_ERR)
	{
		print_error("ERROR\n");
		return(-5);
	}
	if (heap_environ())
	{
		print_error("ERROR Can't heap environ");
		print_error("\n");
		return (-7);
	}

	if (argc > 1)
	{
		fd  = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			print_error("Can't open ");
			print_error(argv[1]);
			print_str("\n");
			return (-4);
		}
	}
	else if (argc == 1)
	{
		if (isatty(0))
		{
			is_interactive = 1;
		}
		else
		{
		}
		fd = STDIN_FILENO;
	}
	exit_status = sh_handler(environ, fd, is_interactive);
	return (exit_status);
}

int sh_handler(char **env, int fd, int is_interactive)
{
	int status = 0;
	int ac;
	char **av = NULL;
	list_t *paths_head = NULL;
	int c_s = 0;
	int done;
	av = (char **)_malloc(100 * sizeof(char *));  /*Is 100 enough ?*/
	if (av == NULL)
		return (-1);
	while (1)
	{
		done = 0;
		if(is_interactive)
		{
			print_str("($) ");
			fflush(stdout);
		}
		c_s = get_command_from_file(fd, av, &ac);
		if (c_s == -1)
		{
			print_error("Memory allocation failure\n");
			shell_exit(av, &ac);
		}
		else if (c_s == -2)         /* EOF */
		{
			if(is_interactive)
				 print_str("\n");
			break;
		}
		else if (c_s == -3)
		{
			continue;
		}
		if (get_PATH(env, &paths_head))
		{
			print_error("Error!! Can't get path");
			print_error("\n");
		}
		else
		{
			if (is_found_and_excecutable(av, paths_head))
			{

			}
			else
			{
				if (fork_and_execve(av, env))
				{
					/*	printf("Error!! Commmand can't get executed\n");*/
				}
				else
				{
				}
				done = 1;
			}
			if (!done)
			{
				if (is_built_in_commnad(av, &ac))
				{	
					print_error("./hsh: ");
					print_error("1: ");
					print_error(av[0]);
					print_error(": not found");
					print_error("\n");
					status = 127;
				}
			}
		}

	}
	free_manager(NULL);
	return (status);
}

