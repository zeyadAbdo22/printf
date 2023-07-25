#include "main.h"
#include <stdarg.h>
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
 * print_string - print a string of characters
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
 * print_number - print an integer number
 * @args: the va_list containing the number to print
 *
 * Return: the number of characters printed
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;
	int divisor = 1;
	char buffer[20];

	if (num < 0)
	{
		_putchar('-');
		len++;
		num *= -1;
	}

	while (num / divisor > 9)
		divisor *= 10;

	while (divisor > 0)
	{
		buffer[len] = (num / divisor) + '0';
		_putchar(buffer[len]);
		len++;
		num %= divisor;
		divisor /= 10;
	}

	return (len);
}

/**
 * print_binary - print an unsigned int as binary
 * @args: the va_list containing the number to print
 *
 * Return: the number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;
	int i;
	char buffer[32];

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; i < 32; i++)
		buffer[i] = (num >> (31 - i) & 1) + '0';

	for (i = 0; i < 32; i++)
	{
		if (buffer[i] == '1')
			break;
	}

	for (; i < 32; i++)
	{
		_putchar(buffer[i]);
		len++;
	}

	return (len);
}

/**
 * _printf - produces output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, i = 0;

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
				len += print_number(args);
			else if (format[i] == 'b')
				len += print_binary(args);
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
