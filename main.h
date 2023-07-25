#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
* struct cnvert - structure  functions with symbols
*
* @op: opereration
* @funct: function assessment
*/
struct cnvert
{
	char *op;
	int (*funct)(va_list);
};
typedef struct cnvert cnvert_t;

int pars(const char *form, cnvert_t f_lst[], va_list arg_lst);
int _printf(const char *format, ...);
int _putchar(char c);
int _print_char(va_list);
int _print_strng(va_list);
int _print_percent(va_list);


#endif
