/*
** EPITECH PROJECT, 2017
** File Name : mysh.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "lk_list.h"
#include "env.h"

int mysh(void)
{
	pid_t pid = getpid();

	init_env();
	if (pid > 0) {
		pid = run();
		return (pid == -1 ? 0 : 1);
	} else {
		my_puterror("An error occured during the program creation\n");
		return (0);
	}
	free_env();
}
