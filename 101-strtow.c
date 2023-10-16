#include "main.h"
#include <stdlib.h>

/**
 * count_word - Counts the number of words in a given string.
 * @s: string to evaluate
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, count, word;

	flag = 0;
	word = 0;

	for (count = 0; s[count] != '\0'; count++)
	{
		if (s[count] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			word++;
		}
	}

	return (word);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, n = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[n] = tmp - c;
				n++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[n] = NULL;

	return (matrix);
}
