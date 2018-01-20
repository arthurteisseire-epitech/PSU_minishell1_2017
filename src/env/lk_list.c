/*
** EPITECH PROJECT, 2017
** File Name : lk_list.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "lk_list.h"

void init_list(void)
{
	env = malloc(sizeof(control_t));
	env->begin = NULL;
	env->end = NULL;
	env->tmp = NULL;
}

int head(char **args)
{
	lk_list_t *new = malloc(sizeof(lk_list_t));

	if (new == NULL)
		return (-1);
	new->name = my_strdup(args[0]);
	if (args[1])
		new->value = my_strdup(args[1]);
	else
		new->value = NULL;
	new->next = NULL;
	if (env->end) {
		env->end->next = new;
		env->end = new;
	} else {
		env->end = new;
		env->begin = new;
	}
	return (0);
}

lk_list_t *find_prev(char *name)
{
	lk_list_t *curr = env->begin;
	lk_list_t *prev = env->begin;

	if (env->begin)
		curr = curr->next;
	while (curr != NULL) {
		if (my_strcmp(curr->name, name) == 0)
			return (prev);
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}

int delete_node(char *name)
{
	lk_list_t *prev = find_prev(name);

	if (prev == NULL) {
		if (env->begin && my_strcmp(name, env->begin->name) == 0)
			free_env();
		return (0);
	}
	env->tmp = prev->next;
	prev->next = prev->next->next;
	free_node(env->tmp);
	env->tmp = NULL;
	return (0);
}
