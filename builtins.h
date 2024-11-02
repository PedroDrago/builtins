#ifndef BUILTINS_H
# define BUILTINS_H
#include <stdlib.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_env_node
{
	char *key;
	char *value;
	struct s_env_node *next;
	struct s_env_node *prev;

}t_env_node;

typedef struct s_env_list
{
	t_env_node *head;
	t_env_node *tail;

}t_env_list;

t_env_node *find_node(t_env_list *env, char *key);
#endif
