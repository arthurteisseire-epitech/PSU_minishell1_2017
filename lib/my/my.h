/*
** EPITECH PROJECT, 2017
** File Name : my.h
** File description:
** By Arthur Teisseire
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);
void my_puterror(char *str);
void my_putstr(char *str);
int my_strlen(char *str);
int my_atoi(char *str);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr(int nb);
int my_strcmp(char const *str1, char const *str2);
char *my_strdup(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalphanum(char *str);

#endif
