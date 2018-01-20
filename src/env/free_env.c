/*
** EPITECH PROJECT, 2017
** File Name : free_env.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "env.h"

void free_node(lk_list_t *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

void free_env(void)
{
	while (env->begin != NULL) {
		env->tmp = env->begin;
		env->begin = env->begin->next;
		free_node(env->tmp);
	}
}
