/*
** EPITECH PROJECT, 2017
** File Name : exec_cmd.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "split.h"
#include "env.h"
#include "get_next_line.h"

void exec_cmd(char *cmd, char **env)
{
	int i = 0;
	int status = -1;
	char **args = split(cmd, " \t");

	if (args && args[0])
		status = execve(args[0], args, env);
	if (status == -1 && my_strcmp(cmd, "") != 0)
		status = exec_with_path(args, env);
	if (status == -1 && my_strcmp(cmd, "") != 0) {
		my_putstr(args[0]);
		my_putstr(": Command not found.\n");
	}
	while (args[i] != NULL) {
		free(args[i]);
		i++;
	}
	free(args);
	if (cmd != NULL)
		free(cmd);
}

int exec_with_path(char **args, char **env)
{
	char *path = find_env(env, "PATH");
	char **paths;
	char *cmd;
	int i = 0;
	char *stock = args[0];

	if (!path)
		return (0);
	while (*path != '=') {
		path++;
	}
	path++;
	paths = split(path, ":");
	while (paths[i] != NULL) {
		cmd = my_realloc(paths[i], "/", 1);
		cmd = my_realloc(cmd, stock, my_strlen(args[0]));
		args[0] = cmd;
		execve(cmd, args, env);
		free(cmd);
		i++;
	}
	return (-1);
}
