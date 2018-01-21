/*
** EPITECH PROJECT, 2017
** File Name : environ.h
** File description:
** by Arthur Teisseire
*/

#ifndef ENV_H
#define ENV_H

#include <stdio.h>

char *find_env(char *var);

int init_env(void);
int my_setenv(char **args);
int my_unsetenv(char **args);
int my_env(char **args);

#endif
