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
	int	len;

}t_env_list;

t_env_node *find_node(t_env_list *env, char *key);

int	ft_unset(char **argv, t_env_list *env);
int	ft_export(char **argv, t_env_list *env);
char	**split_env(char *str);
int	env_delete(t_env_list *list, t_env_node *node);
t_env_list *new_env_list();
t_env_node *new_env_node(char *key, char *value);
t_env_node *find_node(t_env_list *env, char *key);
void	print_split(char **tab);
int	env_add_back(t_env_list *list, t_env_node *node);
void	ft_env(t_env_list *env);
#endif
