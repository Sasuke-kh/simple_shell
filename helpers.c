#include "helpers.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "strings.h"
#include <sys/wait.h>
#include "main.h"
#include <string.h>
#include "memory_manager.h"

int get_command_from_file(int fd, char **av, int *ac)
{
    char *line;
    ssize_t size;
    size_t n = 10000;
    char* token;
    int i = 0;

    line = (char *)_malloc(10000);
    if (line == NULL)
        return (-1);
    size = _getline(&line, &n, fd);
    if (size == -2)
    {
        return (-2);
    }
    else if (size == -1)
    {
        return (-1);
    }
    else if (size == 0)
    {
        return (-3);
    }

    if (line[size - 1] == '\n')
        line[size - 1] = '\0';
    token = _strtok(line, " ");
    /*check if first token is alias replace it with equivelant*/

    while (token != NULL)
    {
        av[i] = _strdup(token);
        token = _strtok(NULL, " ");
        i++;
    }
    if (i == 0)
        return (-3);
    av[i] = NULL;*ac = i;
	return (0);
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
			perror("Errorx!!\n");
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
			result =  _strncmp("PATH", env[i], 4);
			i++;
		}
		if (result == -1)
			return (-1);
		pathLine = env[i-1];
		copy_pathLine = _strdup(pathLine);
		token = _strtok(copy_pathLine + 5, ":");
		while (token != NULL)
		{
			add_node_end(paths_head, token);
			token = _strtok(NULL, ":");
			j++;
		}
	}
	/*print_list(*paths_head);*/
	return (0);
}
int is_found_and_excecutable(char **av, list_t *paths_head)
{
	size_t n1, n2;
	char *testFile;
	list_t *trav_path = paths_head;

	/*check current directory first*/
	if (access(av[0], X_OK) == 0)
	{
		return (0);
	}

	/*check all directories in path*/
	while(trav_path != NULL)
	{	
		n1 = trav_path->len;
		n2 = _strlen(av[0]);
		testFile = (char *)_malloc(n1 + n2 + 2);
		if (testFile == NULL)
			return (-2);
		_strcpy(testFile, trav_path->str);
		_strcat(testFile, "/");
		_strcat(testFile, av[0]);
		if (access(testFile, X_OK) == 0)
		{
			av[0] = testFile;
			return (0);
		}
		trav_path = trav_path->next;
	}	
	return (-1);
}

