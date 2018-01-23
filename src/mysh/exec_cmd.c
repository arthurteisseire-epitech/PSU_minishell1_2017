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
#include "builtins.h"
#include "my_perror.h"

static char *concat_with_slash(char *dest, char *src, int len_src)
{
	int len_dest = my_strlen(dest);
	char *res = malloc(sizeof(char) * (len_dest + len_src + 2));
	int i = 0;
	int j = 0;

	if (res == NULL)
		return (NULL);
	while (dest[i] != '\0') {
		res[i] = dest[i];
		i++;
	}
	res[i] = '/';
	i++;
	while (j < len_src) {
		res[i] = src[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int exec_with_path(char **args)
{
	char *path = get_value("PATH");
	int len_prog = my_strlen(args[0]);
	char **paths;
	char *cmd;
	int i = 0;

	if (!path)
		return (0);
	paths = split(path, ":");
	while (paths[i] != NULL) {
		cmd = concat_with_slash(paths[i], args[0], len_prog);
		if (access(cmd, F_OK) != -1)
			execve(cmd, args, environ);
		if (cmd)
			free(cmd);
		i++;
	}
	return (-1);
}

void exec_cmd(char *cmd, char **args)
{
	int status = -1;

	if (args && args[0] && access(cmd, F_OK) != -1)
		status = execve(args[0], args, environ);
	if (status == -1 && my_strcmp(args[0], "") != 0)
		status = exec_with_path(args);
	if (status == -1 && args[0] != NULL) {
		my_putstr(args[0]);
		my_putstr(": Command not found.\n");
	}
	free_args(args);
	if (cmd)
		free(cmd);
}
