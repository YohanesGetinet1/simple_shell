#ifndef MAIN_H
#define MAIN_H


/**
 * struct op - represents structure to find builtins
 * @command: represents command to be matched w fxn
 * @f: represents function to be matched according to command
 */


typedef struct op


{

	char *command;

	void (*f)(char *buff, char **commands);

}

 built;

#include <stdio.h>

#include <sys/stat.h>

#include <string.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <sys/stat.h>

#define DELIM " \t\r\n\a"

#define BUFFERSIZE 1024


extern char **environ;

char *getlinefxn();

char **tokenfxn(char *buff, int count);

int _strcmp(char *s1, char *s2);

void exitfxn(char *buff, char **commands);

void envfxn(char *buff, char **commands);

int builtinfxn(char *buff, char **commands);

char *loopenvironment();

char *concat(char *token, char **tokens, char *commands);

char *_strcpy(char *dest, char *src);

char *_strdup(char *str);

int ptrcounter(char *buff);

int _strcmp(char *s1, char *s2);

char *getpath(char *commands);

char *_strcat(char *dest, char *src);

int _strlen(char *s);

void piderror(pid_t pid, char *buff, char **commands);

typedef struct built_in
{
	char *str;
	struct built_in *next;
} built_in_t;

void direc_fat(char *str, char **temp);
void obt_dir(void);
void handle_sigint(int sig);
int _strcom (char *str_1, char *str_2);
void _cd(char *arg);
extern char **environ;
void print_env(void);
void error(char *str, int cont, int flag);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(int n);
unsigned int get_pid(void);
unsigned int get_ppid(void);
char *stringdup(const char *str);
int toksize(char *str);
char **tokenize(char *str);
int exec(pid_t c_pid, char **array, int cont);
int str_comp(char **array, int size);
char *_getenv(const char *name);
int _which(char *file);
char *str_concat(char *s1, char *s2, int flag);
int path(char **array, int cont);

#endif
