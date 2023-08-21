#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * main- esta función interpreta el comando el usuario
 * Return:Devuelve cero
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($)", 3);
		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
				break;
			perror("Error al leer la entrada");
			free(input);
			exit(1);
		}
		input[read - 1] = '\0';
		pid = fork();
		if (pid < 0)
		{
			perror("Error al crear el proceso hijo");
			free(input);
			exit(1);
		}
		else if (pid == 0)
		{
			exec_token(input);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
		free(input);
	}
	return (0);
}
