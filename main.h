#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>


#define MAX_ARG 1024

ssize_t getline(char **line, size_t *n, FILE *fp);
#endif /**MAIN_H**/
