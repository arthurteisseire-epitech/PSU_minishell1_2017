/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"
#include "split.h"
#include "builtins.h"

static void handle_status(int wstatus)
{
	if (WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	if (WTERMSIG(wstatus) == FLOATEXCEPT)
		my_putstr("Floating exception\n");
}

static int fork_and_exec(char **args, char *cmd)
{
	pid_t child_pid;
	int wstatus;

	if (!exec_builtins(args)) {
		child_pid = fork();
		if (child_pid == 0) {
			exec_cmd(cmd, args);
			return (0);
		} else if (child_pid == -1)
			return (-1);
		wait(&wstatus);
		handle_status(wstatus);
	}
	return (1);
}

int run(void)
{
	char *cmd = NULL;
	char **args;

	while (1) {
		my_putstr("$> ");
		if (cmd)
			free(cmd);
		if (set_and_check_cmd(&cmd) == 0)
			return (1);
		args = split(cmd, " \t");
		if (fork_and_exec(args, cmd) != 1)
			return (0);
	}
	return (1);
}

int set_and_check_cmd(char **cmd)
{
	*cmd = get_next_line(0);
	if (*cmd == NULL) {
		my_putstr("exit\n");
		return (0);
	}
	if (my_strcmp(*cmd, "exit") == 0) {
		my_putstr("exit\n");
		free(*cmd);
		return (0);
	}
	return (1);
}
