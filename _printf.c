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

	if (format == NULL)
		return (0);
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
				chars_printed += print_char('%');
			else if (format[i + 1] == 'c')
				chars_printed += print_char(va_arg(args, int));
			else if (format[i + 1] == 's')
				chars_printed += print_str(va_arg(args, char*));
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				chars_printed += print_number(va_arg(args, int));
			else if (format[i + 1] == 'b')
				print_binary(va_arg(args, unsigned int), &chars_printed);
			else if (format[i + 1] > 32 && format[i + 1] < 127)
			{
				_putchar(format[i]);
				_putchar(format[i + 1]);
				chars_printed += 2;
			}
			i++;
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

	if (str == (char *)0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}

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
	int digits_printed = 0, i = 1, rem, m = n;

	if (n == INT_MIN)
	{
		rem = -(n % 10);
		n /= 10;
	}

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

	if (m == INT_MIN)
	{
		_putchar(rem + '0');
		digits_printed++;
	}

	return (digits_printed);
}


/**
 * print_binary - function that prints an integer in binary.
 * Prototype: void print_binary(unsigned int n, int *digits_printed);
 * @n: the integer to print in binary.
 * @digits_printed: a pointer to chars_printed.
 * Return: void.
 */

void print_binary(unsigned int n, int *digits_printed)
{
	if (n > 1)
	{
		print_binary((n / 2), digits_printed);
		_putchar((n % 2) + '0');
		(*digits_printed)++;
	}
	else
	{
		if (n == 0)
			_putchar('0');

		if (n == 1)
			_putchar('1');

		(*digits_printed)++;
	}
}
