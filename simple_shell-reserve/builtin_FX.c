#include "shell.h"

/**
 * __exit - Handle "exit" in a shell.
 * @shell: shell_t struct contain information about the shell
 * Return: -2 indicate that the shell have to  exit
 */
int __exit(shell_t *shell)
{
	int exit_code = -1;

	if (shell->argv[1])
	{
		exit_code = atoi(shell->argv[1]);
		if (exit_code < 0)
		{
			shell->status = 2;
			print_error(shell, "Illegal number: ");
			_eputs(shell->argv[1]);
			_eputchar('\n');
		}
	}

	return (exit_code);
}

/**
 * _cd - The current working directory of the shell change
 * @shell: shell_t struct contain information about the shell
 * Return: 0 if successful, 1 otherwise
 */

int _cd(shell_t *shell)
{
	char *new_directory = shell->argv[1] ? shell->argv[1] : getenv("HOME");

	if (new_directory)
	{
		int chdir_ret = chdir(new_directory);

		if (chdir_ret == -1)
		{
			print_error(shell, "can't cd to ");
			_eputs(new_directory);
			_eputchar('\n');
			return (1);
		}
		else
		{
			char buffer[1024];

			_setenv(shell, "OLDPWD", _getenv(shell, "PWD"));
			_setenv(shell, "PWD", getcwd(buffer, sizeof(buffer)));
		}
	}
	else
	{
		_eputs("cd: HOME not set\n");

		return (1);
	}

	return (0);
}
