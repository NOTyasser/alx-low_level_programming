#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_executable - find the path of the command.
 *
 * @command: The name of the executable to search for.
 *
 * Return: A path to the executable on success, NULL on failure.
 */

char *find_executable(const char *command)
{
	char *path = getenv("PATH");

	char *token;

	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	while (token != NULL)
	{
		char full_path[1024];

		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			return (strdup(full_path));
		}

		token = strtok(NULL, ":");
	}

	return (NULL);
}
