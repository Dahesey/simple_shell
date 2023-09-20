/**
  * _command - A function to execute commands
  * @args: Arguments entered
  * Return: Always 0
  */

#include "main.h"
int _command(char **args)
{
	pid_t child_pid;
	int wait_status;

	child_pid = fork();
	if (child_pid < 0)
	{
		wait_status = errno;
		perror("fork");
	}
	else if (child_pid == 0)
		execve(args[0], args, environ);
	else
	{
		wait(&wait_status);
		if (WIFEXITED(wait_status))
		wait_status = WEXITSTATUS(wait_status);
	}
	return (wait_status);
}
