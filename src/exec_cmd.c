/*
** EPITECH PROJECT, 2017
** File Name : exec_cmd.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "split.h"

void exec_cmd(char *cmd, char **env)
{
	int i = 0;
	int status = -1;
	char **args = split(cmd, " \t");

	if (args && args[0])
		status = execve(args[0], args, env);
	if (status == -1 && my_strcmp(cmd, "") != 0) {
		my_putstr(args[0]);
		my_putstr(": command not found\n");
	}
	while (args[i] != NULL) {
		free(args[i]);
		i++;
	}
	free(args);
	if (cmd != NULL)
		free(cmd);
}
