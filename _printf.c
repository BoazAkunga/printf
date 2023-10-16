#include "main.h"

/**
 * write_character - Writes a single character to standard output.
 * @c: The character to write.
 * Return: The number of characters written.
 */

int write_character(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_string - Writes a string to standard output.
 * @str: The string to write.
 *
 * Return: The number of characters written.
 */

int write_string(char *str)
{
	int str_len = 0;

	while (str[str_len] != '\0')
	str_len++;
	return (write(1, str, str_len));
}

/**
 * _printf - A custom printf-like function for formatted output.
 * @format: The format string.
 *
 * Return: The number of characters written.
 */

int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list argsB;

	if (format == NULL)
		return (-1);

	va_start(argsB, format);

	while (*format)
	{
		if (*format != '%')
		{
			char_print += write_character(*format);
		} else
		{
			format++;
		if (*format == '\0')
		{
			break;
		}
		if (*format == '%')
		{
		char_print += write_character('%');
		format++;
		}
			else if (*format == 'c')
			{
				char c = va_arg(argsB, int);

				char_print += write_character(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(argsB, char*);

				char_print += write_string(str);
			}
		}
		format++;
	}

	va_end(argsB);
	return (char_print);
}

