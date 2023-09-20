/**
 * main - Entry point
 * Authors - Cynthia Dodzi  & Cynthia Hyamber
 * @ac: Argument count
 * @av: Array pointer of arguments to be passed
 * Return: Always 0
 */

#include "main.h"

int main(int ac, char *av[])
{
	char *line = NULL;
	size_t n = 0;
	char *prompt = "dahesey ", **args;
	bool_t state = TRUE;
	int cmd_status, cmd_count = 0;
	int mode = isatty(STDIN_FILENO);

	UNUSED(ac);
	while (state)
	{
		if (mode == 1)
			printf("%s", prompt);
		if (getline(&line, &n, stdin) == -1)
			break;
		cmd_count++;
		args = _token(line, " \t\n");
		if (args == NULL)
			continue;
		cmd_status = analyze_commands(args, line, av[0],
						cmd_count, cmd_status);
		free(args);
	}
	if (mode == 1)
		putchar('\n');
	free(line);
	exit(cmd_status);
}
