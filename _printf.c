#include "main.h"

/**
* _printf - function to produce the output according to format
* @format: format according to which the arg will be printed
* Return: No of chars to be printed
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
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}

			else if (*format == 'c')
			{
				char c = va_arg(argsB, int);

				write(1, &c, 1);
				char_print++;
			}

			else if (*format == 's')
			{
				char *str = va_arg(argsB, char*);
				int str_len = 0;

			while (str[str_len] != '\0')
				str_len++;

				write(1, str, str_len);
				char_print += str_len;
			}
		}
		format++;
	}

	va_end(argsB);
	return (char_print);
}
