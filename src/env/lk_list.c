/*
** EPITECH PROJECT, 2017
** File Name : lk_list.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "lk_list.h"

void init_list(control_t *list)
{
	list->begin = NULL;
	list->end = NULL;
	list->tmp = NULL;
}

int head(char **args, control_t *list)
{
	lk_list_t *new = malloc(sizeof(lk_list_t));

	if (new == NULL)
		return (-1);
	new->name = my_strdup(args[1]);
	if (args[2])
		new->value = my_strdup(args[2]);
	else
		new->value = NULL;
	new->next = NULL;
	if (list->end) {
		list->end->next = new;
		list->end = new;
	} else {
		list->end = new;
		list->begin = new;
	}
	return (0);
}

lk_list_t *find_prev(char *name, control_t *list)
{
	lk_list_t *curr = list->begin;
	lk_list_t *prev = list->begin;

	if (list->begin)
		curr = curr->next;
	while (curr != NULL) {
		if (my_strcmp(curr->name, name) != 0)
			return (prev);
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}

int remove(char *name, control_t *list)
{
	lk_list_t *prev = find_prev(name, list);

	if (prev == NULL) {
		if (list->begin && my_strcmp(name, list->begin->name) == 0)
			free_list(list);
		return (0);
	}
	list->tmp = prev->next;
	prev->next = prev->next->next;
	free_node(list->tmp);
	list->tmp = NULL;
	return (0);
}
