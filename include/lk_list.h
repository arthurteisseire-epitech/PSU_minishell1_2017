/*
** EPITECH PROJECT, 2017
** File Name : lk_list.h
** File description:
** by Arthur Teisseire
*/

#ifndef LK_LIST_H
#define LK_LIST_H

#include <stdlib.h>

typedef struct lk_list {
	char *name;
	char *value;
	struct lk_list *next;
} lk_list_t;

typedef struct control {
	lk_list_t *begin;
	lk_list_t *end;
	lk_list_t *tmp;
} control_t;

void init_list(control_t *list);
void free_node(lk_list_t *node);
void free_list(control_t *list);
int head(char **args, control_t *list);
lk_list_t *find_prev(char *name, control_t *list);
int remove(char *name, control_t *list);

#endif
