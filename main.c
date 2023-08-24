#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#define MAX_INPUT_SIZE 1024
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
	int len_input = 0;
	char *args[MAX_INPUT_SIZE];
	char *full_path = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));
	int flag_exec = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($)", 3);
		read = getline(&input, &len, stdin);
		if (read == -1)
			break;
		strtrim(input);
		len_input = strlen(input);
		if (len_input > 0)
		{
			tokenizeInput(input, args, " ");
			if (input[0] == '/' || input[0] == '.')
			{
				strcpy (full_path, args[0]);
				flag_exec = 1;
			}
			else
				flag_exec = get_full_path(args[0], full_path);
		}
		if (flag_exec == 1)
		{
			pid = fork();
			if (pid < 0)
				perror("Error al crear el proceso hijo");
			else if (pid == 0 && len_input > 0)
				exec_token(args, full_path);
			else
				waitpid(pid, NULL, 0);
		}
		flag_exec = 0;
	}
	free(full_path);
	free(input);
	return (0);
}
