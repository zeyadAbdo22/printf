#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_number(int n);
int _printf(const char *format, ...);

#endif
