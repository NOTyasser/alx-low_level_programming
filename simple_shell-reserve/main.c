#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Starting point of the shell program.
 *
 * This function initializes the shell and enters a loop to read user commands,
 * parse them, and execute the specified commands.
 *
 * Return: Always returns 0 to indicate successful execution
 */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *TheCmd = NULL;
	size_t byte = 0;
	char **arguments;
	int i; /* Declare i here due to C90 limitations */
	const char *command;

	while (1)
	{
		turn_on_prompt();
		read_user_cmd(&TheCmd, &byte);

		arguments = pars_args(TheCmd);

		if (arguments == NULL || arguments[0] == NULL)
		{
			continue;
		}

		command = arguments[0];

		lets_execute(command);

		for (i = 0; arguments[i] != NULL; i++)
		{
			free(arguments[i]);
		}
		free(arguments);
	}

	free(TheCmd);

	return (0);
}
