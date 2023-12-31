#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#define MAX_PATH_LENGTH 1024
#define MAX_INPUT_SIZE 1024
/**
  * execute_func- This function handles all the execution of the command
  * Return: Returns zero if getline fails
  */
int execute_func(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int len_input = 0;
	char *args[MAX_INPUT_SIZE];
	char *full_path = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));
	int flag_exec = 0;

	read = getline(&input, &len, stdin);
	if (read == -1)
	{
		free(input);
		free(full_path);
		return (0);
	}
	strtrim(input);
	len_input = strlen(input);
	if (len_input > 0)
	{
		tokenizeInput(input, args, " ");
		flag_exec = get_full_path(args[0], full_path);
		if (flag_exec == 0)
		{
			free(full_path);
			free(input);
			exit(127);
		}
		pid = fork();
		if (pid < 0)
			perror("Error al crear el proceso hijo");
		else if (pid == 0 && len_input > 0)
			execve(full_path, args, environ);
		else
			waitpid(pid, NULL, 0);
	}
	free(full_path);
	free(input);
	return (1);
}
/**
  * strtrim- This function removes trailing and trailing spaces.
  * of string
  * @input: user input
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
  * tokenizeInput - Split an input string into tokens
  * @input: Input string to be split into tokens.
  * @args: Array of pointers to characters where tokens will be stored.
  * @delimiter: is the delimiter that will be used as a guide for
  * separate commands
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
	char *path_copy = NULL;
	char *auxpath = NULL;

	if (command[0] == '/' || command[0] == '.')
	{
		strcpy(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			return (1);
		}
	}
	else
	{
		if (path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", command);
			return (0);
		}
		path_copy = strdup(path);
		auxpath = strtok(path_copy, ":");
		while (auxpath != NULL)
		{
			snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", auxpath, command);
			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (1);
			}
			auxpath = strtok(NULL, ":");
		}
	}
	free(path_copy);
	fprintf(stderr, "./hsh: 1: %s: not found\n", command);
	return (0);
}
