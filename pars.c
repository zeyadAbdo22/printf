#include "main.h"

/**
 * pars - to receive the string and  necessary parameters to
 * print a formated string.
 * @form: it contains the  characters we want.
 * @f_lst: list of  the functions.
 * @arg_lst: list of the argumentents that are passed to the program.
 * Return: total the characters printed.
 */

int pars(const char *form, cnvert_t f_lst[], va_list arg_lst)
{
	int a, b, c_val, prntd_char = 0;

	for (a = 0; form[a] != '\0'; a++)
	{
		if (form[a] == '%')
		{
			for (b = 0; f_lst[b].op != NULL; b++)
			{
				if (form[a + 1] == f_lst[b].op[0])
				{
					c_val = f_lst[b].funct(arg_lst);
					if (c_val == -1)
						return (-1);
					prntd_char += c_val;
					break;
				}
			}
			if (f_lst[b].op == NULL && form[a + 1] != ' ')
			{
				if (form[a + 1] != '\0')
				{
					_putchar(form[a]);
					_putchar(form[a + 1]);
					prntd_char = prntd_char + 2;
				}
				else
					return (-1);
			}
			a = a + 1;
		}
		else
		{
			_putchar(form[a]);
			prntd_char++;
		}
	}
	return (prntd_char);
}
