#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#define MAX_PATH_LENGTH 1024
/**
  * strtrim- Esta funcion quita los espacios atras y adelante
  * de un string
  * @input: Entrada del usuario
  */
void strtrim(char *input)
{
	int i = strlen(input) - 1;

	while (i >= 0 && (input[i] == ' ' || input[i] == '\n' || input[i] == '\0'))
	{
		input[i] = '\0';
		i--;
	}
	i = 0;
	while (input[i] && (input[i] == ' ' || input[i] == '\n' || input[i] == '\0'))
	{
		i++;
	}
	memmove(input, input + i, strlen(input) - i + 1);
}
/**
  * tokenizeInput - Divide una cadena de entrada en tokens
  * y los almacena en un arreglo.
  * @input: Cadena de entrada que se va a dividir en tokens.
  * @args: Arreglo de punteros a caracteres donde se almacenarán los tokens.
  * @delimiter: es el delimitador que se usara como guia para
  * separar los comandos
  */
void tokenizeInput(char *input, char **args, char *delimiter)
{
	char *token = strtok(input, delimiter);
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	args[i] = NULL;
}
/**
 * get_full_path - Construct the full path for a command
 * @command: The command entered by the user
 * @full_path: puntero donde se guardará la ruta completa
 * Return: A dynamically allocated string containing the full path,
 * or NULL if memory allocation fails
 */
int get_full_path(const char *command, char *full_path)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *auxpath = NULL;

	if (path_copy == NULL)
	{
		perror("Error getting PATH");
	}
	auxpath = strtok(path_copy, ":");
	while (auxpath != NULL)
	{
		snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", auxpath, command);
		if (access(full_path, X_OK) == 0)
		{
			return (1);
		}
		auxpath = strtok(NULL, ":");
	}
	perror("Error PATH No ejecutable");
	return (0);
}
