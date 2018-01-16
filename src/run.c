/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

int run(char **env)
{
	char *cmd;
	pid_t child_pid;

	do {
		if ((cmd = get_next_line(0)) == NULL)
			return (-1);
		child_pid = fork();
		if (child_pid == 0) {
			exec_cmd(cmd, env);
			return (0);
		} else if (child_pid == -1)
			return (0);
		wait(NULL);
	} while (my_strcmp(cmd, "exit") != 0);
	return (child_pid);
}
