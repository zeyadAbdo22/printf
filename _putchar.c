#include "main.h"
#include <unistd.h>
/**
 * _putchar - Prints a character.
 *
 * @c: char to print.
 *
 * Return: int.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
