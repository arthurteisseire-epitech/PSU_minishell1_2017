/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

static int set_cmd(char **cmd)
{
	*cmd = get_next_line(0);
	if (*cmd == NULL)
		return (0);
	if (my_strcmp(*cmd, "exit") == 0)
		return (0);
	return (1);
}

int run(char **env)
{
	char *cmd = NULL;
	pid_t child_pid;

	while (1) {
		if (cmd)
			free(cmd);
		if (!set_cmd(&cmd))
			return (1);
		child_pid = fork();
		if (child_pid == 0) {
			exec_cmd(cmd, env);
			return (0);
		} else if (child_pid == -1)
			return (-1);
		wait(NULL);
	} 
	return (1);
}
