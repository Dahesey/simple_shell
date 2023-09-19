/**
  * main - Entry point
  * Authors - Cynthia Dodzi & Cynthia Hyamber
  * Return: Always 0
  */

#include "main.h"

int main(void)
{
	char *token = strtok(line, " ");
	char *command = token;
	int status;
	int exit_status;
	pid_t child_pid;
	int count = 0;
	char *args[1000];
	char *line = NULL;

	if (command != NULL)
	{
		args[count++] = command;

		while ((token = strtok(NULL, " ")) != NULL)
			args[count++] = token;
	}
	args[count] = NULL;

	child_pid = fork();

	if (child_pid == -1)
		perror("fork");
	else if (child_pid == 0)
	{
		execvp(command, args);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	waitpid(child_pid, &status, 0);
	if (WIFEXITED(status))
	{
		exit_status = (WEXITSTATUS(status));
		printf("child_pid exited with status: %d\n", exit_status);
	}
	free(line);
	return (0);
}
