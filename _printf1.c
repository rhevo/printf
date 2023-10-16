#include "main.h"
/**
 * _printf1 - output format
 * @format: format
 * Return: return 0 or 1
 */
int _printf1(const char *format, ...)
{
	int count = 0;
	const char *ptr = format;
	va_list arg_list;
	va_start(arg_list, format);

	while (*ptr != '\0')
	{
		if(*ptr == 'd' || *ptr == 'i')
		{
			int num = va_arg(arg_list, int);
			printf("%d", num);
			count++;
		}
		else if (*ptr == '%')
		{
			putchar('%');
			count++;
		}
		else
		{
			putchar(*ptr);
			count++;
		}
	}
	ptr++;
	va_end(arg_list);
	return count;
}
