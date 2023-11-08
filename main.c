#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int sh_script(char **argv, char **env);
int sh_non_interactive(char **env);
int sh_interactive(char **env);

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
	char **av;

	while (status)
	{
		printf("($) ");
		status = get_command(av, ac);
		if(status == -2)
			continue;
	}
}

int get_command(char **av, int ac)
{
	char *line;
	ssize_t size;
	size_t n = 0;

	line = (char *)malloc(100);
	size = getline(&line, &n, stdin);
	if (size == -1)
		return (-2);
	printf("size = %ld\n", size);
	printf("n = %lu\n", n);
	if (line[size - 1] == '\n')
		line[size - 1] = '\0';
	printf("command  = %s\n", line);

}
