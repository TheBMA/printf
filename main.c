#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	/* simple sentence - works */
	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");

	/* character - works */
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');

	/* string - works */
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	/* percentage - works */
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");

	/* decimal - %i works for decimal, doesn't for octal or hexadecimal */
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Value of INT_MIN: [%d, %i]\n", INT_MIN, INT_MIN);
	printf("Value of INT_MIN: [%d, %i]\n", INT_MIN, INT_MIN);

	/* Empty string */
	_printf("\n");
	printf("\n");

	/* Backslash character */
	_printf("\\\n");
	printf("\\\n");

	/* single quotes */
	_printf("hello 'd'\n");
	printf("hello 'd'\n");

	/* Binary converter */
	_printf("%b\n", 98);

	/* Single % sign */
	printf("%\n");
	_printf("%\n");
	_printf("Hello % world\n");

	return (0);
}
