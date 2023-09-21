#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct liststr - singly linked_list
 * @num: number of field
 * @str: string
 * @next: point to next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct shell - struct contain information about the shell
 * @arg: string generated from getline contain arguements
 * @argv: array of strings generated from arg
 * @path: tring path for the current command
 * @argc: argument count
 * @line_count: error count
 * @err_num: error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @alias: alias node
 * @env_changed: on if environ was changed
 * @status: return status of the last exec command
 * @cmd_buf: address of pointer to cmd_buf on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which to read line input
 * @histcount: history line number count
 */

typedef struct shell
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} shell_t;

/**
 * struct builtin - it contains a builtin string and related function
 * @type: builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(shell_t *);
} builtin_table;


int loophsh(char **);

int is_cmd(shell_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(shell_t *, char *, char *);

int shell(shell_t *, char **);
int get_builtin(shell_t *);
void find_cmd(shell_t *);
void fork_cmd(shell_t *);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);
int bfree(void **);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

int __exit(shell_t *);
int _cd(shell_t *);
int _myalias(shell_t *);

void clear_info(shell_t *);
void set_info(shell_t *, char **);
void free_info(shell_t *, int);

int _erratoi(char *);
void print_error(shell_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int interactive(shell_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

ssize_t get_input(shell_t *);
int _getline(shell_t *, char **, size_t *);
void sigint_handler(int);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

char *_getenv(shell_t *, const char *);
int _myenv(shell_t *);
int _mysetenv(shell_t *);
int _myunsetenv(shell_t *);
int populate_env_list(shell_t *);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

char **get_environ(shell_t *);
int _unsetenv(shell_t *, char *);
int _setenv(shell_t *, char *, char *);

int is_chain(shell_t *, char *, size_t *);
void check_chain(shell_t *, char *, size_t *, size_t, size_t);
int replace_alias(shell_t *);
int replace_vars(shell_t *);
int replace_string(char **, char *);

char **pars_args(const char *cmdInput);

/**
 * turn_on_prompt - Display prompt $
 *
 * return: void
 **/
void turn_on_prompt(void); /* Display prompt */

char *find_executable(const char *command);

/**
 * DoPrint - used instead of printf*
 *
 * @text: text to be printed
 * return: void
 *
 **/
void DoPrint(const char *text); /* Used instead of printf */

/**
 *lets_execute - executes command
 *
 *@command: command to be exexuted
 *return: void
 **/
void lets_execute(const char *command);
void read_user_cmd(char **the_cmd, size_t *byte);

#endif
