#include "main.h"

/**
 * _printf - reeive string and what  necessary in  parameters to
 * print a formated string
 * @form: It contain  the desired characters
 * Return: return the character printed.
 */
int _printf(const char *form, ...)
{

	int _printed_chars;

	cnvert_t f_ls[] = {
		{"c", _print_char},
		{"s", _print_strng},
		{"%", _print_percent},
		{"i", _print_int},
		{"d", _print_int},
		{NULL, NULL}
	};

	va_list arg_lst;

	if (form == NULL)
		return (-1);

	va_start(arg_lst, form);

	_printed_chars = pars(form, f_ls, arg_lst);

	va_end(arg_lst);

	return (_printed_chars);
}
