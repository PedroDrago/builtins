#include "builtins.h"

void	print_split(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		printf("%s\n", tab[i++]);
}

t_env_node *find_node(t_env_list *env, char *key)
{
	t_env_node *current;
	size_t len;

	current = env->head;
	len = 0;
	while(current)
	{
		len = ft_strlen(key);
		if (ft_strncmp(key, current->key, len) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_env_node *new_env_node(char *key, char *value)
{
	t_env_node *node;

	node = malloc(sizeof(t_env_node));
	if (!node)
		return(NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_env_list *new_env_list()
{
	t_env_list *list;

	list = malloc(sizeof(t_env_list));
	if (!list)
		return(NULL);
	list->head = NULL;
	list->tail= NULL;
	return (list);
}

int	env_add_back(t_env_list *list, t_env_node *node)
{
	if (!list || !node)
		return (0);
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
		return (1);
	}
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
	return (1);

}

int	env_delete(t_env_list *list, t_env_node *node)
{
	if (!list || !node)
		return (0);
	if (node == list->head)
	{
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	else if (node == list->tail)
	{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node->value);
	free(node->key);
	free(node);
	return (1);
}

void	ft_env(t_env_list *env)
{
	t_env_node	*current;

	current = env->head;
	while(current)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}

char	**split_env(char *str)
{
	int	i;
	int	len;
	char	**splited;

	i = 0;
	len = ft_strlen(str);
	splited = malloc((sizeof(char *) * 3));
	if (!splited)
		return(NULL);
	while(str[i])
	{
		if (str[i] == '=')
		{
			splited[0] = ft_substr(str, 0, i);
			if (!splited[0])
			{
				free(splited);
				return(NULL);
			}
			splited[1] = ft_substr(str, i + 1, len);
			if (!splited[0])
			{
				free(splited[0]);
				free(splited);
				return(NULL);
			}
			splited[2] = NULL;
			return (splited);
		}
		i++;
	}
	free(splited);
	return (NULL);
}


int	is_valid_key(char *key)
{
	int	i;

	i = 1;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	while(key[i])
	{
		if(!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// {"export", "CHAVE1=VALOR1", "CHAVE2=VALOR2", ... , NULL}
int	ft_export(char **argv, t_env_list *env)
{
	t_env_node	*node;
	char **key_value;
	int	i;

	i = 1;
	if (!argv || !env)
		return (1);
	while(argv[i])
	{
		// HOME=/home/pdrago -> "HOME", "/home/pdrago"
		key_value = split_env(argv[i]);
		if (!key_value)
			exit(1);
		if (!is_valid_key(key_value[0]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("`: not a valid identifier", 2);
			return (1);
		}
		node = new_env_node(key_value[0], key_value[1]);
		if (!node)
			exit(1);
		env_add_back(env, node);
		i++;
	}
	return (0);
}

int	ft_unset(char **argv, t_env_list *env)
{
	int	i;
	size_t	len;
	t_env_node *current;
	t_env_node *tmp;

	i = 1;
	while(argv[i])
	{
		current = env->head;
		while (current)
		{
			tmp = current->next;
			len = ft_strlen(argv[i]);
			if (ft_strncmp(argv[i], current->key, len) == 0)
				env_delete(env, current);
			current = tmp;
		}
		i++;
	}
	return (1);
}

// int main(int argc, char *argv[], char *envp[])
// {
// 	t_env_list	*env;
// 	t_env_node	*node;
// 	char **key_value;
// 	int	i;
//
// 	env = new_env_list();
// 	i = 0;
// 	while(envp[i])
// 	{
// 		// HOME=/home/pdrago -> "HOME", "/home/pdrago"
// 		key_value = split_env(envp[i]);
// 		if (!key_value)
// 			exit(1);
// 		node = new_env_node(key_value[0], key_value[1]);
// 		if (!node)
// 			exit(1);
// 		env_add_back(env, node);
// 		i++;
// 	}
// 	char *my_argv[] = {"export", "OPA=VALOR", "1OPA2=VALOR2", NULL};
// 	ft_export(my_argv, env);
// 	char *my_argv2[] = {"unset", "OPA", "OPA2", NULL};
// 	ft_unset(my_argv2, env);
// 	ft_env(env);
// 	return 0;
// }
