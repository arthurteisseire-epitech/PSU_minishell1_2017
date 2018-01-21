/*
** EPITECH PROJECT, 2017
** File Name : head.c
** File description:
** by Arthur Teisseire
*/

#include "lk_list.h"
#include "my.h"
#include "mysh.h"

static void set_end(lk_list_t *new)
{
	if (env->end) {
		env->end->next = new;
		env->end = new;
	} else {
		env->end = new;
		env->begin = new;
	}
}

int head(char **args)
{
	lk_list_t *new = malloc(sizeof(lk_list_t));
	lk_list_t *node = find_node(args[0]);

	if (node) {
		node->value = my_strdup(args[1]);
		return (0);
	}
	if (new == NULL)
		return (-1);
	new->name = my_strdup(args[0]);
	if (args[1])
		new->value = my_strdup(args[1]);
	else
		new->value = NULL;
	new->next = NULL;
	set_end(new);
	return (0);
}

lk_list_t *find_node(char *name)
{
	lk_list_t *curr = env->begin;

	while (curr != NULL) {
		if (my_strcmp(curr->name, name) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

char *get_value(char *name)
{
	lk_list_t *node = find_node(name);

	if (node)
		return (node->value);
	return (NULL);
}
