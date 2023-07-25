#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen -  the length about string
 * @s: The string whose length will be returned
 *
 * Return:  lengt sting
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
		length++;

	return (length);
}

/**
 * _puts - writes the string *s to the stdout
 * @s:  string to  print
 *
 * Return: length by function
 */
int _puts(const char *s)
{
	char *p;

	p = "(null)";

	if (s == NULL)
		return (write(1, p, _strlen(p)));
	else
		return (write(1, s, _strlen(s)));
}
