#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sh_script(char **argv, char **env);
int sh_non_interactive(char **env);
int sh_interactive(char **env);
int get_command(char **av, int *ac);
int free_av_memory(char **av, int ac);
int fork_and_execve(char **av, char **env);

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

}

int sh_non_interactive(char **env)
{


}
int sh_interactive(char **env)
{	
	char *line;
	ssize_t size;
	size_t n;
	int status = 1;
	int ac;
	char **av = NULL;
	int i = 0;
	av = (char **)malloc(10 * sizeof(char *));
	while (status)
	{
		printf("($) ");
		get_command(av, &ac);
		if(status == -2)
			continue;
		fork_and_execve(av, env);	
		free_av_memory(av, ac);
	}
	free(av);
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
	copy_line = line;
	size = getline(&line, &n, stdin);
	if (size == -1)
		return (-2);
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
}

int free_av_memory(char **av, int ac)
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
			return -1;
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) != pid)
		{
			return -1;
		}
		else
		{
			if (WIFEXITED(status) != 1)
			{
				printf("status of child process = %d\n", WEXITSTATUS(status));
				return -1;
			}
		}

	}
	return 0;
}
