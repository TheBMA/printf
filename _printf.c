#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * Prototype: int _printf(const char *format, ...);
 *
 * @format: a string of characters.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 *
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
			if (format[i + 1] == '%')
			{
				chars_printed += print_char('%');
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				chars_printed += print_char(va_arg(args, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				chars_printed += print_str(va_arg(args, char*));
				i++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				chars_printed += print_number(va_arg(args, int));
				i++;
			}
		}
	}
	va_end(args);
	return (chars_printed);
}

/**
 * print_char - function that prints a char.
 * Prototype: int print_char(char c);
 * @c: a character.
 * Return: the number of characters printed.
 */

int print_char(char c)
{
	_putchar(c);

	return (1);
}


/**
 * print_str - function that prints a string of chars.
 * Prototype: int print_str(char *str);
 * @str: pointer to a string.
 * Return: the number of characters printed.
 */

int print_str(char *str)
{
	int i, chars_printed = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		chars_printed++;
	}

	return (chars_printed);
}


/**
 * print_number - a function that prints an integer.
 * Prototype: int print_number(int n);
 * @n: an integer.
 * Return: the number of digits printed.
 */

int print_number(int n)
{
	int digits_printed = 0, i = 1, rem;

	if (n == INT_MIN)
	{
		_putchar('-');
		digits_printed++;
		rem = n % 10;
		n /= 10;
		n = -n;

		while((n / i) >= 10)
			i *= 10;

		while(i >= 1)
		{
			_putchar((n / i) + '0');
			digits_printed++;
			n %= i;
			i / 10;
		}
		_putchar(rem + '0');
		digits_printed++;
	}

	else
	{
		if (n < 0)
		{
			_putchar('-');
			digits_printed++;
			n = -n;
		}
		
		while ((n / i) >= 10)
		i *= 10;

		while (i >= 1)
		{
			_putchar((n / i) + '0');
			digits_printed++;
			n %= i;
			i /= 10;
		}
	}

	return (digits_printed);
}
