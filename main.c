#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * main- this function interprets the command the user
 * Return: returns zero
 */
int main(void)
{
	int exit_flag = 1;

	while (exit_flag)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($)", 3);
		exit_flag = execute_func();
	}
	return (0);
}
