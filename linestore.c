#include "main.h"


/**
 * getlinefxn - function will get line and store in a buffer
 * Return: returns pointer to buffer
 */


char *getlinefxn()

{
	char *buff = NULL;
	size_t buffsize = 0;
	ssize_t x;

	x = getline(&buff, &buffsize, stdin);
	if (buff == NULL)
	{
		perror("Error");
		return (NULL);
	}
	if (x == EOF)
	{
		free(buff);
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (x == 1)
	{
		free(buff);
		return (NULL);
	}
	if (x == 0)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
