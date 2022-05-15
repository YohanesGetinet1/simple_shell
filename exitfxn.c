#include "main.h"

/**
 * exitfxn - function will exit out of terminal
 * @buff: represents buffer holding line of commands
 * @commands: represents pointer pointing to tokenized commands
 * Return: function returns void
 */


void exitfxn(char *buff, char **commands)

{
	free(buff);
	free(commands);
	exit(0);
}
