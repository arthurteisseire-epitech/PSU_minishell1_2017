/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

int run(char *cmd, char **env)
{
	int pid;

	do {
		pid = fork();
		if (pid == 0)
			exec_cmd(cmd, env);
		else if (pid > 0 && wait(NULL) == 0)
			kill(0, SIGKILL);
		cmd = get_next_line(0);
		if (cmd == NULL)
			return (-1);
	} while (my_strcmp(cmd, "exit") != 0);
	return (pid);
}
