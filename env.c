#include "env.h"
#include "memory_manager.h"
#include "strings.h"

extern char **environ;

static int  copy_all_env(char **old_env, char **new_env);

int heap_environ(void)
{
	char **new_env = _malloc(ENV_SIZE * sizeof(char *));
	if (!new_env)
		return (-1);
	/*copy all variabls from original environ variable*/
	if (copy_all_env(environ, new_env))
		return (-1);

	//update environ to be new_env
	environ = new_env;
	return (0);
}


static int  copy_all_env(char **old_env, char **new_env)
{
	int i = 0;

	while (old_env[i])
	{
		new_env[i] = _strdup(old_env[i]);
		if(new_env[i] == NULL)
			return (-1);
		i++;
	}
	/*Append NULL at end of new_env*/
	new_env[i] = NULL;
	return (0);
}


void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

