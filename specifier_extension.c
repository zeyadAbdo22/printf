#include "main.h"
/**
 * _print_char - To print the character
 * @ls: arguments list
 * Return: to return the amount of character printed
 */
int _print_char(va_list ls)
{
	_putchar(va_arg(ls, int));
	return (1);
}

/**
 * _print_strng - To print the string
 * @ls: arguments list
 * Return: to return the amount of character printed
 */
int _print_strng(va_list ls)
{
	int i;
	char *stri;

	stri = va_arg(ls, char *);
	if (stri == NULL)
		stri = "(null)";
	for (i = 0; stri[i] != '\0'; i++)
		_putchar(stri[i]);
	return (i);
}

/**
 * _print_percent - to print a percent
 * @ls: arguments list
 * Return: to return the amount of characters printed.
 */
int _print_percent(__attribute__((unused))va_list ls)
{
	_putchar('%');
	return (1);
}

/**
 * _print_int - To print an integer
 * @ls: arguments list
 * Return: the number of characters printed
 */
int _print_int(va_list ls)
{
	int num = va_arg(ls, int);
	int count = 0;

	if (num < 0)
	{
		_wr_char('-');
		num = -num;
		count++;
	}

	if (num / 10)
		count += _print_int_H(num / 10);

	_putchar(num % 10 + '0');
	count++;

	return (count);
}

/**
 * _print_int_H - Function to recursively print an integer
 * @num: the integer to print
 * Return: the number of characters printed
 */
int _print_int_H(int num)
{
	int count = 0;

	if (num / 10)
		count += _print_int_H(num / 10);

	_wr_char(num % 10 + '0');
	count++;

	return (count);
}
