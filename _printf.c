#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * print_char - print a single character
 * @args: the va_list containing the character to print
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - print a string of characters.
 *
 * @args: the va_list containing the string to print
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}

/**
 * _printf - produces output according to a format.
 *
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == '%')
			{
				_putchar('%');
				len++;
			}
			else if (format[i] == 'c')
				len += print_char(args);
			else if (format[i] == 's')
				len += print_string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				len += print_number(va_arg(args, int));
			else
			{
				_putchar('%');
				_putchar(format[i]);
				len += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

