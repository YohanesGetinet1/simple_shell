#include "main.h"


/**
 * loopenvironment - function will loop through environment
 * Return: function will return path of match
 */



char *loopenvironment()
{
	int i;
	char *path = NULL;
	char *finalpath = NULL;
	char *copy;
	char *stri = "PATH";

	i = 0;
	while (environ[i] != NULL)
	{
		copy = _strdup(environ[i]);
		if (copy == NULL)
		{
			free(copy);
			return (NULL);
		}
		path = strtok(copy, "=");
		if (_strcmp(path, stri) == 0)
		{
			finalpath = environ[i];
		}
		i++;
	}
	free(copy);
	return (finalpath);
}


/**
 * concat - function will append command to token
 * @token: represents single pointer token
 * @tokens: represents double pointer token
 * @commands: represents command to be added
 * Return: function returns concatenated string
 */



char *concat(char *token, char **tokens, char *commands)
{
	int k;
	int x;
	struct stat st;

	k = 0;
	while (tokens != NULL)
	{
		_strcat(tokens[k], "/");
		if (tokens[k] == NULL)
		{
			free(token);
			free(tokens);
			return (NULL);
		}
		_strcat(tokens[k], commands);
		if (tokens[k] == NULL)
		{
			free(token);
			free(tokens);
			return (NULL);
		}
		x = stat(tokens[k], &st);
		if (x == 0)
		{
			free(token);
			return (tokens[k]);
		}
		k++;
	}
	return (NULL);
}



/**
 * getpath - function will find the path and append the desired command
 * @commands: represents pointer to first index of command
 * Return: function will return newly concatenated pointer
 */


char *getpath(char *commands)
{
	int index;
	char *finalpath, *token = NULL, **tokens = NULL;
	char *holder;

	finalpath = loopenvironment();
	if (finalpath == NULL)
		return (NULL);
	token = malloc(sizeof(char) * 1024);
	if (token == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
	{
		free(token);
		return (NULL);
	}
	token = strtok(finalpath, ":=");
	tokens[0] = token;
	index = 1;
	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, ":=");
		index++;
	}
	tokens[index] = NULL;
	holder = concat(token, tokens, commands);
	if (holder == NULL)
	{
		free(token);
		free(tokens);
		return (NULL);
	}
	else
		return (holder);
	free(token);
	free(tokens);
	return (NULL);
}
