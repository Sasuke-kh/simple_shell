#ifndef _ENV_H_
#define _ENV_H_
#define ENV_SIZE 100
extern char **environ;

int heap_environ(void);
void print_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
#endif
