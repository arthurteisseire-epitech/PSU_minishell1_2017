/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"
#include "tools.h"

void exec_cmd(char *cmd, char **env)
{
	int i = 0;
	char **args = split(cmd, ' ');

	//for (int i = 0; args[i] != NULL; i++)
	//	printf("%s\n", args[i]);
	execve(args[0], args, env);
	while (args[i] != NULL) {
		free(args[i]);
		i++;
	}
	free(cmd);
}

int main(int ac, char **av, char **env)
{
	pid_t pid = getpid();
	char *cmd = "";

	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take two and only two argument\n");
		return (84);
	}
	if (pid > 0) {
		while (my_strcmp(cmd, "exit") != 0) {
			cmd = get_next_line(0);
			if (cmd == NULL)
				return (84);
			pid = fork();
			wait(NULL);
			if (pid == 0) {
				exec_cmd(cmd, env);
			} 
		}
	} else {
		my_puterror("An error occured during the program creation\n");
		return (84);
	}
	return (0);
}
