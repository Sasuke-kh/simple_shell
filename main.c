#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sh_script(char **argv, char **env);
int sh_non_interactive(char **env);
int sh_interactive(char **env);
int get_command(char **av, int *ac);
int free_av_memory(char **av, int ac);

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
	while (status--)
	{
		printf("($) ");
		get_command(av, &ac);
		if(status == -2)
			continue;
		for (i = 0; i < ac; i++)
			printf("command[%d] = %s\n", i, av[i]);
			printf("ac = %d\n", ac);
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
	printf("size = %ld\n", size);
	printf("n = %lu\n", n);
	if (line[size - 1] == '\n')
		line[size - 1] = '\0';
	printf("command  = %s\n", line);

	token = strtok(line, " ");
	while (token != NULL)
	{
		printf(" %s\n", token);
		av[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
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
		printf("freeing [%d] = %s\n", i, av[i]);
		free(av[i]);
	}
}
