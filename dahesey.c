/**
  * main - Entry point
  * Authors - Cynthia Dodzi  & Cynthia Hyamber
  * Return: Always 0
  */

#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t n = 0;
	char *prompt = "dahesey$ ";
	bool state = true;
	ssize_t read;

	while(state)
	{
		printf("%s", prompt);
		read = getline(&line, &n, stdin);
		
		if (read == -1)
		{
			printf("\n");
			state = false;
		}
		else
			printf("error:%scannot be found\n", line);
	}
	free(line);
	return (0);
}	
