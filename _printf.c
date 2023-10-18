#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: No of characters printed
 */
int _printf(const char *format, ...)
{
	va_list mylist_of_args;
	char c;
	int charac_print = 0;
	int len = 0;

	if (format == NULL)
		return (-1);
	va_start(mylist_of_args, format);
	while (*format)
	{
	if (*format != '%')
	{
	charac_print += write(1, format, 1); }
	else
	{
	format++;
	if (*format == '\0')
	break;
	if (*format == '%')
	{
	charac_print += write(1, format, 1); }
	else if (*format == 'c')
	{
	c = va_arg(mylist_of_args, int);
	charac_print += write(1, &c, 1); }
	else if (*format == 's')
	{
	char *str = va_arg(mylist_of_args, char*);

	while (str[len])
	len++;
	charac_print += write(1, str, len);
	}
	}
	format++;
	}
	va_end(mylist_of_args);
	return (charac_print);
}

