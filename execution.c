#include "libft/libft.h"
#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_env_list *create_env(char *envp[])
{
	t_env_node	*node;
	t_env_list	*env;
	char **key_value;
	int	i;

	env = new_env_list();
	i = 0;
	while(envp[i])
	{
		// HOME=/home/pdrago -> "HOME", "/home/pdrago"
		key_value = split_env(envp[i]);
		if (!key_value)
			exit(1);
		node = new_env_node(key_value[0], key_value[1]);
		if (!node)
			exit(1);
		env_add_back(env, node);
		i++;
	}
	return (env);
}

char **convert_env_to_array(t_env_list *list)
{
	char	**envp;
	char	*str;
	char	*tmp;
	int	i;
	t_env_node *current;

	i = 0;
	current = list->head;
	envp = malloc((sizeof(char *) * list->len + 1));
	if (!envp)
		return(NULL);
	while(current)
	{
		str = ft_strjoin(current->key, "=");
		envp[i] = ft_strjoin(str, current->value);
		free(str);
		current = current->next;
		i++;
	}
	return envp;
}

void	ft_perror(char *error, char *arg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);

}
// "ls" | {"-la", "libft"}
void	execute(char *command, char *argv[], t_env_list *env)
{
	char *path;
	char **splited_path;
	char *tmp;
	char *command_path;
	char **envp;
	int i;

	envp = convert_env_to_array(env);
	execve(command, argv, envp);
	t_env_node *node= find_node(env, "PATH");
	if (node)
	{
		path = node->value;
		splited_path = ft_split(path, ':');
		i = 0;
		while(splited_path[i])
		{
			tmp = ft_strjoin(splited_path[i], "/"); 
			command_path = ft_strjoin(tmp, command);
			free(tmp);
			if (access(command_path, F_OK) == 0)
			{
				if (access(command_path, X_OK) == 0)
					execve(command_path, argv, envp);
				perror("minishell: ");
			}
			i++;
		}
	}
	perror("minishell: ");
}

int main(int argc, char *argv[], char *envp[])
{
	t_env_list *env = create_env(envp);
	char *my_argv[] = {"cat", "-e", "teste", NULL};
	execute("cat", my_argv, env);
	return 0;
}
