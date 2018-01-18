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
int exec_with_path(char **args);
int run();
int mysh();
int set_and_check_cmd(char **cmd);

#endif
