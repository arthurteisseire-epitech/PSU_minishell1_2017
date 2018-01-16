/*
** EPITECH PROJECT, 2017
** File Name : mysh.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"

int mysh(char **env)
{
	pid_t pid = getpid();
	char *cmd = "";

	if (pid > 0) {
		run(cmd, env);
		return (1);
	} else {
		my_puterror("An error occured during the program creation\n");
		return (0);
	}
}
