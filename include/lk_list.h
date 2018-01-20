/*
** EPITECH PROJECT, 2017
** File Name : lk_list.h
** File description:
** by Arthur Teisseire
*/

#ifndef LK_LIST_H
#define LK_LIST_H

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

extern control_t *env;

void init_list(void);
void free_node(lk_list_t *node);
void free_env(void);
int head(char **args);
lk_list_t *find_prev(char *name);
int delete_node(char *name);

#endif
