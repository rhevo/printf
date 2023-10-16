#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: string to the format
 * Return: return 1 or 0
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0, ch_print = 0;
	va_list arg_list;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(arg_list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				_putchar(va_arg(arg_list, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				ch_print = _putstr(va_arg(arg_list, char*));
						i++;
						count += (ch_print - 1);
			}
			else
			{
				_putchar('%');
			}
		}
		else
		{
			_putchar(format[i]);
		}
		count++;
	}
	va_end(arg_list);
	return (count);
}
