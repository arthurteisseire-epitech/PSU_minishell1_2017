/*
** EPITECH PROJECT, 2017
** File Name : lk_list.c
** File description:
** by Arthur Teisseire
*/

#include "lk_list.h"
#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

void init_list(void)
{
	env = malloc(sizeof(control_t));
	env->begin = NULL;
	env->end = NULL;
	env->tmp = NULL;
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
		if (env->begin && my_strcmp(name, env->begin->name) == 0) {
			env->tmp = env->begin;
			env->begin = env->begin->next;
			free_node(env->tmp);
			env->tmp = NULL;
		}
		return (0);
	}
	if (prev->next->next == NULL)
		env->end = prev;
	env->tmp = prev->next;
	prev->next = prev->next->next;
	free_node(env->tmp);
	env->tmp = NULL;
	return (0);
}

char **env_to_array(void)
{
	int i = 0;
	int len_env = 0;
	lk_list_t *curr = env->begin;
	char **array;

	while (curr != NULL) {
		len_env++;
		curr = curr->next;
	}
	array = malloc(sizeof(char *) * (len_env + 1));
	if (array == NULL)
		return (NULL);
	array[len_env] = NULL;
	curr = env->begin;
	while (curr != NULL) {
		array[i] = my_realloc(curr->name, curr->value, my_strlen(curr->value));
		curr = curr->next;
	}
	return (array);
}
