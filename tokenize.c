#include "main.h"

/**
 * ptrcounter - function will count number of pointers fed from getline
 * @buff: represents pointer from getline to be evaluated
 * Return: function will return count of pointers
 */

int ptrcounter(char *buff)
{
	int index, i, count;
	char *separator;

	count = 2;
	separator = ": ";
	index = 0;
	while (buff[index] != '\0')
	{
		i = 0;
		while (separator[i] != '\0')
		{
			if (buff[index] == separator[i])
				count++;
			i++;
		}
		index++;
	}
	return (count);
}


/**
 * tokenfxn - function will tokenize line
 * @buff: represents pointer to buffer holding line
 * @count: represents total count of pointers
 * Return: function returns pointer to array
 */


char **tokenfxn(char *buff, int count)
{
	char **commands;
	size_t index;
	char *token;

	commands = malloc(sizeof(char *) * (count + 2));
	if (commands == NULL)
	{
		free(buff);
		return (NULL);
	}
	token = strtok(buff, DELIM);
	commands[0] = token;
	index = 1;
	while (token != NULL)
	{
		if (commands == NULL)
		{
			free(buff);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		commands[index] = token;
		index++;
	}
	return (commands);
}
