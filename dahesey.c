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

	getline(&line, &n, stdin);

	while(state)
	{
		printf("%s", prompt);
		getchar();
	}
	return (0);
}	
