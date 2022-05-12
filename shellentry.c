#include "main.h"

/**
 * builtinfxn - function will see if input is a shell builtin
 * @buff: represents buffer to be read
 * @commands: represents commands to be analyzed
 * Return: returns zero if builtin, one if not
 */


int builtinfxn(char *buff, char **commands)
{
	int i, j;
	built in[] = {
		{"exit", exitfxn},
		{"env", envfxn},
		{NULL, NULL},
	};

	i = 0;
	while (commands != NULL && commands[i] != '\0')
	{
		j = 0;
		while (in[j].command != NULL)
		{
			if ((_strcmp(commands[i], (in[j].command)) == 0) &&
			    (_strlen(commands[i]) == _strlen(in[j].command)))
			{
				(in[j].f)(buff, commands);
				free(buff);
				free(commands);

				return (0);

			}
			j++;
		}
		i++;
	}

	return (1);
}



/**
 * piderror - function will evaluate if there's a process error
 * @pid: represents process to be eval'd
 * @buff: represents pointer to incoming buffer
 * @commands: represents commands to be executed
 * Return: function returns void
 */


void piderror(pid_t pid, char *buff, char **commands)
{
	if (pid < 0)
		perror("Wait");
	free(buff);
	free(commands);
}


/**
 * main - function will handle most function calls
 * Return: function will always return 0
 */


int main(void)
{
	char *buff = NULL, **commands; pid_t pid; int status, count, x, y;
	struct stat st;

	while (1)
	{
		write(STDOUT_FILENO, "TalkToMe$ ", 11);
		buff = getlinefxn();
		if (buff == NULL)
			continue;
		count = ptrcounter(buff);
		commands = tokenfxn(buff, count);
		x = builtinfxn(buff, commands);
		if (x == 0)
			continue;
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			if (commands[0] != NULL)
			{
				y = stat(commands[0], &st);
				if (y != 0)
					commands[0] = getpath(commands[0]);
				execve(commands[0], commands, NULL);
				perror("Error");
			}
			else
				free(buff); free(commands);
		}
		else if (pid > 0)
		{
			piderror(pid, buff, commands);
			wait(&status);
		}
	}
	return (0);
}
