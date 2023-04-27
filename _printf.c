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
	int count = 0;
	char ch;
	char *str;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				ch = va_arg(args, int);
				putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					putchar(*str);
					count++;
					str++;
				}
			}
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
