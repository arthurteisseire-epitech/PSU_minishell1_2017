/*
** EPITECH PROJECT, 2017
** File Name : my_exec.h
** File description:
** by Arthur Teisseire
*/

#ifndef MY_EXEC_H
#define MY_EXEC_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void exec_cmd(char *cmd, char **env);
int run(char **env);
int mysh(char **env);
int set_and_check_cmd(char **cmd);

#endif
