#include "shell.h"

/**
 * unset_alias - Unset an alias in the shell
 * @info: shell_t struct contain infos about the shell
 * @str: string alias to unset
 * Return: Always if 0 success, if 1 error.
 */
int unset_alias(shell_t *info, char *str)
{
	int ret = 0;

	char *alias_name = strtok(str, "=");

	if (alias_name == NULL)
		return (1);

	ret = delete_alias(&(info->alias), alias_name);

	return (ret);
}

/**
 * set_alias - Set an alias in the shell
 * @info: shell_t struct contain information about the shell
 * @str: string alias to set
 * Return: Always if success, if 1 error.
 */
int set_alias(shell_t *info, char *str)
{
	char *alias_name = strtok(str, "=");
	char *alias_value = strtok(NULL, "=");

	if (alias_name == NULL || alias_value == NULL)
		return (1);

	unset_alias(info, alias_name);
	return (add_alias(&(info->alias), alias_name, alias_value));
}

/**
 * print_alias - it will print an alias string
 * @node: alias node to print
 * Return: Always if 0 success, if 1 error.
 */
int print_alias(list_t *node)
{
	if (node)
	{
		printf("%s='%s'\n", node->str, node->str + strlen(node->str) + 1);
		return (0);
	}
	return (1);
}

/**
 * _myalias - List, Add, or remove aliases in the shell
 * @info: shell_t struct contain information about the shell
 * Return: Always 0.
 */
int _myalias(shell_t *info)
{
	int i;

	if (info->argc == 1)
	{
		list_t *node = info->alias;

		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		char *arg = info->argv[i];

		if (strchr(arg, '='))
		{
			set_alias(info, arg);
		}
		else
		{
			list_t *node = find_alias(info->alias, arg);

			if (node)
			{
				print_alias(node);
			}
		}
	}

	return (0);
}
