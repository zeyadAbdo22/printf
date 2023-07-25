#include "main.h"

/**
 * print_number - Prints an integer.
 *
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */

int print_number(int n)
{
	int digit, divisor = 1, printed_chars = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	if (n < 0)
	{
		_putchar('-');
		printed_chars++;
		n = -n;
	}

	while (n / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		digit = (n / divisor) % 10;
		_putchar(digit + '0');
		printed_chars++;
		divisor /= 10;
	}

	return (printed_chars);
}
