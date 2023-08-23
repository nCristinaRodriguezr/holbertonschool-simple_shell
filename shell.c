#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#define MAX_INPUT_SIZE 1024
#define MAX_PATH_LENGTH 4096
/**
 * exec_token- esta función tokeniza una entrada de usuario y
 * ejecuta el comando
 * @input: Entrada del usuario
 */
void exec_token(char *input)
{
	char *args[MAX_INPUT_SIZE];

	tokenizeInput(input, args, " ");
	if (args[0] != NULL)
	{		
		char *command_path = full_path(args[0]);
			            
		if (command_path != NULL) 
		{
			pid_t child_pid = fork();
			if (child_pid == 0) 
				execve(command_path, args, NULL);
				perror("Error al ejecutar el comando");
				exit(1);
			else if (child_pid > 0)
				int status;
				waitpid(child_pid, &status, 0);
			else 
				perror("Error al crear el proceso hijo");
			else
				fprintf(stderr, "Comando no encontrado: %s\n", args[0]);
		}
	}	
}
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
 * Return: A dynamically allocated string containing the full path,
 * or NULL if memory allocation fails
 */
char *full_path(char *file)
{
	char *path_env = getenv("PATH");
	if (path_env == NULL)
       	{
		fprintf(stderr, "Variable de entorno PATH no definida.\n");
		return (NULL);
	}
	char *path = strdup(path_env);
	if (path == NULL)
	{
		perror("Error al duplicar el valor de PATH");
		return (NULL);
	}
	char *token = strtok(path, ":");
	while (token != NULL)
	{
		char full[MAX_PATH_LENGTH];
		snprintf(full, sizeof(full), "%s/%s", token, file);
		struct stat st;
		if (stat(full, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free(path);
			return strdup(full);
		}
		token = strtok(NULL, ":");
	}
	free(path); 
	return (NULL);
}
