#include "env.h"
#include "memory_manager.h"
#include "strings.h"

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	int result = 1;
	int name_len = 0;
	char *value = NULL;

	name_len = _strlen(name);

	while(environ[i] != NULL && result != 0)
	{
		result =  _strncmp(name , environ[i], name_len);
		i++;
	}
	if (result)
		return (NULL);

	value = _strdup(environ[i - 1] + name_len + 1);
	if (value == NULL)
		return (NULL);
	return (value);
}
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;
    int result = 1;
    int name_len = 0;
	int value_len = 0;
	char *new_name = NULL;
	
    name_len = _strlen(name);
	value_len = _strlen(value);

    while(environ[i] != NULL && result != 0)
    {
        result =  _strncmp(name , environ[i], name_len);
        i++;
    }
	if (result == 0)
	{
		if (overwrite == 0)
		{
			return (0);
		}
		else
		{
			/*replace the vairable with another with the new value*/

			i--;  											 /*go back to index of matched name*/
			new_name = _malloc(name_len + value_len + 2);    /* '=' + '\0'*/
			if(new_name == NULL)
				return (-1);
			new_name[0] = '\0';
			_strcat(new_name, name);
			_strcat(new_name, "=");
			_strcat(new_name, value);
			environ[i] = new_name;
			return (0);
		}
		
	}
    else
	{
       /*Not found . just append it to the list*/
		    new_name = _malloc(name_len + value_len + 2);    /* '=' + '\0'*/
            if(new_name == NULL)
                return (-1);
            new_name[0] = '\0';
            _strcat(new_name, name);
            _strcat(new_name, "=");
            _strcat(new_name, value);
            environ[i] = new_name;
			environ[i + 1] = NULL;    /* append NULL to end*/
            return (0);
	}
}

int _unsetenv(const char *name)
{
    int i = 0;
    int result = 1;
    int name_len = 0;
    char *value = NULL;

    name_len = _strlen(name);

    while(environ[i] != NULL && result != 0)
    {
        result =  _strncmp(name , environ[i], name_len);
        i++;
    }
    if (result)
        return (0);

	/*shift all following variables*/
	i--;
	while(environ[i] != NULL)
	{
		environ[i] = environ[i + 1];
		i++;
	}

    return (0);
}

