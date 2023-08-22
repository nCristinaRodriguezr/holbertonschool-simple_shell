#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_INPUT_SIZE 1024
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
	char *comands[MAX_INPUT_SIZE];
	char *miniInput = NULL;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($)", 3);
		read = getline(&input, &len, stdin);
		if (read == -1)
			break;
		tokenizeInput(input, comands, "\n");
		while (comands[i] != NULL)
		{
			miniInput = *comands[i];
			strtrim(miniInput);
			miniInput[read - 1] = '\0';
			pid = fork();
			if (pid < 0)
				perror("Error al crear el proceso hijo");
			else if (pid == 0)
				exec_token(miniInput);
			else
				waitpid(pid, NULL, 0);
			i++;
		}
	}	
	free(input);
	return (0);
}
