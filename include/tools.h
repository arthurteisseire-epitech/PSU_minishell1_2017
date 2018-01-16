/*
** EPITECH PROJECT, 2017
** File Name : tools.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOLS_H
#define TOOLS_H

int skip_first_flags(char **str, char flag);
char **split(char *str, char flag);
char *get_next_word(char **str, char flag);
int len_first_word(char *str, char flag);
int count_words(char *str, char flag);

#endif
