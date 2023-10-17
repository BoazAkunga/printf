#include "main.h"

/**
 * _printf - Prints formatted output to stdout
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int charac_print = 0;
	char c;
	va_list mylist_of_args;

	if (format == NULL)
	return (-1);
	va_start(mylist_of_args, format);
	while (*format)
	{
	if (*format != '%')
	charac_print += write(1, format++, 1);
	else
	{
	format++;
	if (*format == '\0')
	break;
	if (*format == '%')
	charac_print += write(1, format++, 1);
	else if (*format == 'c')
	c = va_arg(mylist_of_args, int);
	charac_print += write(1, &c, 1);
	if (*format == 's')
	{
	char *str = va_arg(mylist_of_args, char*);
	int len = 0;

	while (str[len])
	len++;
	charac_print += write(1, str, len);
	}
	format++;
	}
	}

	va_end(mylist_of_args);
	return (charac_print);
}
