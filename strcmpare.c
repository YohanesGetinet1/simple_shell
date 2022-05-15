#include "main.h"

/**
 * _strcmp - function will compare two strings
 * @s1: represents pointer to first string
 * @s2: represents pointer to second string
 * Return: function will return a number based off comparison of strings
 */


int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] < s2[a] || s1[a] > s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
