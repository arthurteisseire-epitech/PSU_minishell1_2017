/*
** EPITECH PROJECT, 2017
** File Name : free_list.c
** File description:
** by Arthur Teisseire
*/

#include "lk_list.h"

void free_node(lk_list_t *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

void free_list(control_t *list)
{
	while (list->begin != NULL) {
		list->tmp = list->begin;
		list->begin = list->begin->next;
		free_node(list->tmp);
	}
	init_list(list);
}
