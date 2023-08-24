#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
  * exec_token- esta función tokeniza una entrada de usuario y
  * ejecuta el comando
  * @input: Entrada del usuario
  */
void exec_token(char *input, char **args)
{
	if (args[0] != NULL)
	{
		execve(args[0], args, NULL);
	}
	else
	{
		perror("Error al ejecutar el comando");
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
