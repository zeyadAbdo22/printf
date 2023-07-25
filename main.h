#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct conv_spec - Strct conv_spec
 * @conv_spec: The conversion specifier
 * @f: The function associated
 */
typedef struct conv_spec
{
	char *conv_spec;
	int (*f)(char c, const char *s, long int n, unsigned long int m);
} conv_spec_t;

int _putchar(char c);
int _puts(const char *s);
int _printf(const char *format, ...);

int _print_char(char c, const char *s, long int n, unsigned long int m);
int _print_string(char c, const char *s, long int n, unsigned long int m);
int _print_int(char c, const char *s, long int n, unsigned long int m);
int (*get_f(const char *s))(char, const char *, long int, unsigned long int);

void print_binary(unsigned long int n);
void print_integer(unsigned long int n);
void print_unsigned_integer(unsigned long int n);
int number_digits_binary(long int n);
int number_digits(long int n);

#endif
