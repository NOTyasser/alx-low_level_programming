#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * pars_args - parses command-line arguments from user input.
 *
 * @cmdInput: user input string
 *
 * Return: An array of argument strings.
 **/
char **pars_args(const char *cmdInput)
{
	char **args = malloc(sizeof(char *) * 1024);

	int arg_count;

	char *token;

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok((char *)cmdInput, " ");

	arg_count = 0;

	while (token != NULL)
	{
		args[arg_count++] = strdup(token);
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	return (args);
}
