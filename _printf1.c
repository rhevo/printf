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
	int i;
	int d;

	va_list pars;

	if (format == NULL)
		return (-1);

	va_start(pars, format);

	while (*format)
	{
		if(*format == 'd')
		{
			d = va_arg(pars, int);
			write(1, &d, 1);
			c_pri++;
		}
		else if (*format == 'i')
		{
			i = va_arg(pars, int);
			write(1, &i, 1);
			c_pri++;
		}

	format++;
	}
	va_end(pars);

	return (c_pri);
}
