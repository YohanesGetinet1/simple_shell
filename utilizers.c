#include "main.h"

/**
 * *_strcpy - function will copy a string from one pointer to another
 * Return: function will return string to dest
 * @dest: represents pointer that will receive the copied string
 * @src: represents pointer that holds the string to be copied
 */


char *_strcpy(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (src[a] != '\0')
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	return (dest);
}


/**
 * _strdup - function will return pointer to copied string
 * @str: represents string to be copied
 * Return: function will return destination string
 */


char *_strdup(char *str)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	ptr = malloc(_strlen(str) + 1);
	if (ptr != NULL)
		_strcpy(ptr, str);
	return (ptr);
}


/**
 * *_strcat - Function will concatenate two strings
 * @src: represents the string that will be added
 * @dest: represents the final appended string
 * Return: the function will return the final appended string
 */

char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;

	while (dest[b] != '\0')
	{
		b++;
	}
	while (src[a] != '\0')
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}


/**
 * _strlen - function will return the length of a string
 * Return: function will return zero if compiled correctly
 * @s: represents address given from main function
 */


int _strlen(char *s)
{
	int length;

	length = 0;
	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

