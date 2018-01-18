/*
** EPITECH PROJECT, 2017
** File Name : mysh.h
** File description:
** by Arthur Teisseire
*/

#ifndef MY_EXEC_H
#define MY_EXEC_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

void exec_cmd(char *cmd);
int run(void);
int mysh(void);
int set_and_check_cmd(char **cmd);
void skip_path_var(char **var);
char *get_var_content(char *var);

#endif
