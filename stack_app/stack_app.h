#ifndef __STACK_APP_H__
#define __STACK_APP_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LOG_FILE  "stack.log"
void ispair(char* file_name);
void print_to_log(FILE* log_fp, char* message);
#endif
