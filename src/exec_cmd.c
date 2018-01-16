/*
** EPITECH PROJECT, 2017
** File Name : exec_cmd.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "tools.h"

void exec_cmd(char *cmd, char **env)
{
	int i = 0;
	char **args = split(cmd, ' ');

	execve(args[0], args, env);
	while (args[i] != NULL) {
		free(args[i]);
		i++;
	}
	free(args);
	if (cmd != NULL)
		free(cmd);
}
