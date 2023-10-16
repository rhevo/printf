#include "main.h"
/**
 * _putstr - to print string
 * @s: string to print
 * Return: no of character printed
 */
int _putstr(char *s)
{
	int count = 0;

	if (s)
	{
		while (s[count] != '\0')
		{
			_putchar(s[count]);
			count++;
		}
	}
	else
	{
		_putstr("(null)");
		count = 6;
	}
	return (count);
}
