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
	int len_input = 0;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($)", 3);
		read = getline(&input, &len, stdin);
		if (read == -1 || strcmp(input, "exit") == 0)
			break;
		strtrim(input);
		len_input = strlen(input);
		pid = fork();
		if (pid < 0)
			perror("Error al crear el proceso hijo");
		else if (pid == 0 && len_input > 0)
			exec_token(input);
		else
			waitpid(pid, NULL, 0);
	}
	free(input);
	return (0);
i}
