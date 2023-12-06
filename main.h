#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char c);
int print_str(char *str);
int print_number(int n);
void print_binary(unsigned int n, int *digits_printed);

#endif
