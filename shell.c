#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#define MAX_INPUT_SIZE 1024
/**
 * exec_token- esta función tokeniza una entrada de usuario y
 * ejecuta el comando
 * @input: Entrada del usuario
 */
void exec_token(char *input)
{
	char *args[MAX_INPUT_SIZE];
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL && strcmp(token, " ") != 0)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	if (args[0] != NULL)
	{
		execve(args[0], args, NULL);
	}
	else
	{
		perror("Error al ejecutar el comando");
	}
}
