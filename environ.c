#include "main.h"
/**
  * builtin_env - prints the environment
  */
void builtin_env(void)
{
	int i;
	char **env = environ;
	if (env)
	{
		for (i = 0; env[i]; i++)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
