/**
  * env - A function to handle enironment builtin
  * Return: Always 0
  */

#include "main.h"
int env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return (0);
}
/**
  * exit_command - A function to handle exit command builtin
  * @args: Arguments
  * @line: Line read
  * Return: Always 0
  * @name: char pointer
  * @cmd_count: command count
  * @status: Exit status
  */
int exit_command(char **args, char *line,
		char *name, int cmd_count, int status)
{
	char *tmp;
	int i = 0;

	if (args[1] == NULL)
	{
		free(args);
		free(line);
		exit(status);
	}

	tmp = args[1];
	while (tmp[1])
	{
		if (isdigit(tmp[i]) == 0)
		{
			fprintf(stderr, "%s: %d: %s: illegal number: %s\n",
				name, cmd_count, args[0], args[1]);
		return (2);
		}
	}
	status = atoi(args[1]);
	free(args);
	free(line);
	exit(status);
}
