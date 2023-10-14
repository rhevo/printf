#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: format string
 * @...: variadic arguments
 *
 * Return: he number of characters printed
 */

int _printf(const char *format,
		...)
{
	int c_pri = 0;
	char *s;
	char c;

	va_list pars;

	if (format == NULL)
		return (-1);

	va_start(pars, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				c_pri++;
			}
			else if (*format == 'c')
			{
				c = va_arg(pars, int);
				write(1, &c, 1);
				c_pri++;
			}
			else if (*format == 's')
			{
				s = va_arg(pars, char *);
				write(1, s, strlen(s));
				c_pri += strlen(s);
			}
		}
		else
		{
			write(1, format, 1);
		}

		format++;
	}

	va_end(pars);

	return (c_pri);

}
