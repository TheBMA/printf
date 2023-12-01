#include "main.h"

/*
* _printf - a function that produces output according to a format.
* Prototype: int _printf(const char *format, ...);
*
*
* Returns: the number of characters printed
* (excluding the null byte used to end output to strings)
*/

int _printf(const char *format, ...)
{
	int chars_printed = 0, i;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			chars_printed++;
		}
		else
		{
			if (format[i + 1] == 'c' || format[i + 1] == 's')
			{
				//we increment the chars_printed by the the return value of this function.
				chars_printed += str_or_char(format[i + 1], /*va_arg()*/);
			}
		}
	}

	return(chars_printed);
}

/*
* str_or_char - function that prints a char or a string of chars.
*
* Returns: the number of characters printed.
*/
int str_or_char(char *c, ...)
{
	int chars_printed = 0;

	return (chars_printed);
}
