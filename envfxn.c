#include "main.h"
#include <unistd.h>


/**
 * _putchar - function will print single character at a time
 * @c: represents character to be printed
 * Return: returns one on success
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * envfxn - function will print environment
 * @buff: represents buffer to be voided
 * @commands: represents commands that will be voided
 * Return: function returns void
 */


void envfxn(char *buff, char **commands)
{
	int i, j;
	(void) buff;
	(void) commands;

	i = 0;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
