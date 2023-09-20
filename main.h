#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>


typedef int bool_t;
#define TRUE 1
#define FALSE 0
#define UNUSED(x) ((void)(x))


extern char **environ;
void print_args(char **args);
int _command(char **args);
int env(void);
int exit_command(char **args, char *line, char *name,
		int cmd_count, int status);
int analyze_commands(char **args, char *line, char *name,
			int cmd_count, int status);
char *path_handler(char *command, char *new_path);
int validate_commands(char **args, char *name, int cmd_count);
char **_token(char *input, char *lim);
size_t num_tokens(char *input, char *lim);

#endif /**MAIN_H**/
