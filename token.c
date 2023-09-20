/**
  * num_tokens - A function to count number of tokens passed
  * @input: String entered
  * @lim: Separator of tokens
  * Return: Always 0
  */

#include "main.h"
size_t num_tokens(char *input, char *lim)
{
	size_t count;
	char *token;

	count = 0;
	token = strtok(input, lim);
	while (token)
	{
		count++;
		token = strtok(NULL, lim);
	}
	return (count);
}
/**
  * _token - A functiont to tokenise a string
  * @input: String entered
  * @lim: Separator
  * Return: Always 0
  */
char **_token(char *input, char *lim)
{
	char *token, *inputcpy;
	char **tokens_array;
	size_t len, i = 0;

	inputcpy = strdup(input);
	if (inputcpy == NULL)
		return (NULL);
	len = num_tokens(inputcpy, lim);
	tokens_array = malloc(sizeof(char *) * (len + 1));
	if (tokens_array == NULL)
		return (NULL);

	token = strtok(input, lim);
	while (token)
	{
		tokens_array[i] = token;
		token = strtok(NULL, lim);
		i++;
	}
	tokens_array[i] = NULL;

	free(inputcpy);
	return (tokens_array);
}
