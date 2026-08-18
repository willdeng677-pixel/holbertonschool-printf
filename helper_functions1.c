#include "main.h"

/**
 * print_char - prints one character
 * @c: character
 *
 * Return: 1
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @str: string
 *
 * Return: number of printed characters
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of printed characters
 */
int print_int(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += print_char('-');
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_int(num / 10);

	count += print_char((num % 10) + '0');

	return (count);
}

/**
 * print_unsigned_base - converts and prints unsigned ints to base 10, 8, or 16
 * @num: number to print
 * @base: base radix (8, 10, or 16)
 * @uppercase: 1 for uppercase hex letters, 0 for lowercase
 * Return: number of printed characters
 */
int print_unsigned_base(unsigned int num, int base, int uppercase)
{
    char *lookup = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int count = 0;

    if (num / base)
        count += print_unsigned_base(num / base, base, uppercase);

    count += print_char(lookup[num % base]);
    return (count);
}
