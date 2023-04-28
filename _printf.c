#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Produces output according to a format.
 * @format: input string.
 * Return: number of chars printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list arg;
	char *str;

	va_start(arg, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			if (format[i] == '%')
				count += putchar('%');
			else if (format[i] == 'c')
				count += putchar(va_arg(arg, int));
			else if (format[i] == 's')
			{
				str = va_arg(arg, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += putchar(*(str++));
			}
			else
			{
				count += putchar('%');
				count += putchar(format[i]);
			}
		}
		else
			count += putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
