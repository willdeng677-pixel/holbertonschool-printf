#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += print_char(format[i]);
		}
		else
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			switch (format[i])
{
case 'c':
	count += print_char(va_arg(args, int));
	break;

case 's':
	count += print_string(va_arg(args, char *));
	break;

case 'd':
case 'i':
	count += print_int(va_arg(args, int));
	break;

case 'u':
	count += print_unsigned_base(va_arg(args, unsigned int), 10, 0);
	break;

case 'o':
	count += print_unsigned_base(va_arg(args, unsigned int), 8, 0);
	break;

case 'x':
	count += print_unsigned_base(va_arg(args, unsigned int), 16, 0);
	break;

case 'X':
	count += print_unsigned_base(va_arg(args, unsigned int), 16, 1);
	break;
	
case '%':
	count += print_char('%');
	break;

default:
	count += print_char('%');
	count += print_char(format[i]);
	break;
}
		}

		i++;
	}

	va_end(args);

	return (count);
}
