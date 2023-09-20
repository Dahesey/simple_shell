/**
 * analyze_commands - A function to analyze commands entered
 *@args: Arguments passed
 *@line: line to be read
 * @name: name of command
 * @cmd_count: command count
 * @status: Status after exit
 * Return: 1
 */

#include "main.h"
int analyze_commands(char **args, char *line, char *name, int cmd_count,
		int status)
{
	if (strcmp(args[0], "env") == 0)
		return (env());
	else if (strcmp(args[0], "exit") == 0)
		return (exit_command(args, line, name,
			cmd_count, status));
	else
		return (validate_commands(args, name, cmd_count));

	return (1);
}

/**
 * validate_commands - A function to validate command paths
 * @args: Arguments passed
 * @name: name of program
 * @cmd_count: command count
 * Return: Always command status
 */
int validate_commands(char **args, char *name, int cmd_count)
{
	char path[BUFSIZ];
	int cmd_status;
	struct stat status;

	if (stat(args[0], &status) == 0)
		cmd_status = _command(args);
	else if (path_handler(args[0], path))
	{
		args[0] = path;
		cmd_status = _command(args);
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: command not found\n",
			name, cmd_count, args[0]);
		cmd_status = 127;
	}
	return (cmd_status);
}

/**
 * path_handler - A functiont o handle the path of commands
 * @command: char pointer
 * @new_path: A new path
 * Return: NULL
 */
char *path_handler(char *command, char *new_path)
{
	struct stat status;
	char *path, **path_array;
	char pathcpy[BUFSIZ];
	int i = 0;

	path = getenv("PATH");
	strcpy(pathcpy, path);
	path_array = _token(pathcpy, ":");
	if (path_array == NULL)
		return (NULL);

	while (path_array[i])
	{
		strcpy(new_path, path_array[i]);
		strcat(new_path, "/");
		strcat(new_path, command);

		if (stat(new_path, &status) == 0)
		{
			free(path_array);
			return (new_path);
		}
		*new_path = '\0';
		i++;
	}
	free(path_array);
	return (NULL);
}

