#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * DoPrint - used instead of printf*
 *
 * @text: text to be printed
 * return: void
 *
 **/

void DoPrint(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}

/**
 * turn_on_prompt - Display prompt $
 *
 * return: void
*/

void turn_on_prompt(void)
{
	DoPrint("$ ");
}

/**
 *lets_execute - executes command
 *
 *@command : command to be exexuted
 *return: void
 **/
void lets_execute(const char *command)
{
	char cmd[100];
	int result;

	snprintf(cmd, sizeof(cmd), "%s", command);

	result = system(cmd);

	if (result == -1)
	{
		perror("system");
		exit(EXIT_FAILURE);
	}
	else if (result != 0)
	{
		printf("Command failed: %s\n", command);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Command executed successfully: %s\n", command);
	}
}

/**
 *read_user_cmd - reads user input using / parsing.
 *@byte: characters count
 *@the_cmd: command input
 *
 * return: void
 *
 **/
void read_user_cmd(char **the_cmd, size_t *byte)
{
	ssize_t read = getline(the_cmd, byte, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("error.\n");
			exit(EXIT_FAILURE);
		}
	}

	/* Remove the trailing newline character, if it exists */
	if ((*the_cmd)[read - 1] == '\n')
	{
		(*the_cmd)[read - 1] = '\0';
	}
}
