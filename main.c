#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <sys/types.h>
#include <sys/wait.h>

int sh_script(char **argv, char **env);
int sh_non_interactive(char **env);
int sh_interactive(char **env);
int get_command(char **av, int *ac);
void free_av_memory(char **av, int ac);
int fork_and_execve(char **av, char **env);
int get_PATH(char **env, list_t **paths_head);
int is_found_and_excecutable(char **av, list_t *paths_head);
int is_alias(char **av);
int is_built_in_commnad(char **av);

int main(int argc, char **argv, char **env)
{
	
	if (argc > 1)
	{
		sh_script(argv, env);
	}
	else if (argc == 1)
	{
		if (isatty(0))
			sh_interactive(env);
		else
			sh_non_interactive(env);
	}	

	return (0);
}

int sh_script(char **argv, char **env)
{
	return (0);
}

int sh_non_interactive(char **env)
{
	return (0);
}
int sh_interactive(char **env)
{	
	int status = 1;
	int ac;
	char **av = NULL;
	list_t *paths_head = NULL;
	
	av = (char **)malloc(100 * sizeof(char *));  /*Would it be a problem ? is 100 enough ?*/
	while (status)
	{
		printf("($) ");
		if(get_command(av, &ac))
		{
			printf("Error!! Can't get command\n");
			continue;	
		}
		//is_alias(av);
		
		if(get_PATH(env, &paths_head))
		{	
			printf("Error!! Can't get path\n");
			continue;
		}
		if (is_found_and_excecutable(av, paths_head))
		{
			printf("Error!! Command not found\n");
			continue;
		}
		//is_built_in_commnad(av);

		if(fork_and_execve(av, env))
		{
			printf("Error!! Commmand can't get executed\n");
			continue;
		}
		free_av_memory(av, ac);
	}
	free(av);
	free_list(paths_head);
	return (0);
}

int get_command(char **av, int *ac)
{
	char *line;
	char *copy_line;
	ssize_t size;
	size_t n = 0;
	char* token;
	int i = 0;

	line = (char *)malloc(100);
	if (line == NULL)
		return (-1);
	copy_line = line;
	size = getline(&line, &n, stdin);
	if (size == -1)
	{
		free(copy_line);
		return (-2);
	}
	if (line[size - 1] == '\n')
		line[size - 1] = '\0';

	token = strtok(line, " ");

	while (token != NULL)
	{
		av[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	av[i++] = NULL;	
	*ac = i;
	free(line);
	free(token);
	free(copy_line);
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


int fork_and_execve(char **av, char **env)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
		return -1;

	if(pid == 0)
	{
		if(execve(av[0], av, env) == -1)
		{
			perror("Error!!\n");
			return -2;
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) != pid)
		{
			return -3;
		}
		else
		{
			if (WIFEXITED(status) != 1)
			{
				printf("status of child process = %d\n", WEXITSTATUS(status));
				return -4;
			}
		}

	}
	return 0;
}

int get_PATH(char **env, list_t **paths_head)
{	
	int i = 0;
	int j = 0;
	int result = -1;
	char *pathLine;
	char *copy_pathLine;
	char *token;

	if(*paths_head == NULL)
	{
		while(env[i] != NULL && result != 0)
		{
			result =  strncmp("PATH", env[i], 4);
			i++;
		}
		if (result == -1)
			return (-1);
		pathLine = env[i-1];
		copy_pathLine = strdup(pathLine);
		token = strtok(copy_pathLine + 5, ":");
		while (token != NULL)
		{
			add_node_end(paths_head, token);
			token = strtok(NULL, ":");
			j++;
		}
		free(token);
		free(copy_pathLine);
	}
	/*print_list(*paths_head);*/
	return (0);
}
int is_found_and_excecutable(char **av, list_t *paths_head)
{
	size_t n1, n2;
	char *testFile;
	list_t *trav_path = paths_head;

	//check current directory first
	if (access(av[0], X_OK) == 0)
	{
		return (0);
	}
	
	//check all directories in path
	while(trav_path != NULL)
	{	
		n1 = trav_path->len;
		n2 = strlen(av[0]);
		testFile = (char *)malloc(n1 + n2 + 2);
		if (testFile == NULL)
			return (-2);
		strcpy(testFile, trav_path->str);
		strcat(testFile, "/");
		strcat(testFile, av[0]);
		if (access(testFile, X_OK) == 0)
		{
			av[0] = testFile;
			return (0);
		}
		trav_path = trav_path->next;
	}	
	return (-1);
}

int is_alias(char **av)
{

;	return (0);
}


int is_built_in_commnad(char **av)
{
	
	return (0);
}
