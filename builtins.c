#include "builtins.h"
#include "libft/libft.h"
#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	argv_len(char *argv[])
{
	int	i;
	
	i = 0;
	while(argv && argv[i])
		i++;
	return (i);
}

int	update_vars(t_env_list *env, char *path)
{
	t_env_node *node;
	char	current_path[PATH_MAX];

	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("minishell: cd");
		return (0);
	}
	node = find_node(env, "PWD");
	if (!node)
		return (0);
	free(node->value);
	node->value = path;
	node = find_node(env, "OLD_PWD");
	if (!node)
		return (0);
	free(node->value);
	node->value = ft_strdup(current_path);
	return (1);
}

int	cd(char *argv[], t_env_list *env)
{
	int	len;
	int status;
	t_env_node *node;
	char	*path;

	len = argv_len(argv);
	if (len > 2)
	{
		perror("minishell: cd: too many arguments");
		return (1);
	}
	if (len == 2)
		path = argv[1];
	else
	{
		node = find_node(env, "HOME");
		if (!node)
		{
			perror("minishell: cd: HOME not set");
			return (1);
		}
		path = node->value;
	}
	if (chdir(path) < 0)
		perror("minishell: cd");
	return (update_vars(env, path));
}

int	pwd()
{
	char	buffer[PATH_MAX];
	if (getcwd(buffer, sizeof(buffer)) == NULL)
	{
		perror("minishell: pwd");
		return (1);
	}
	printf("%s\n", buffer);
	return (0);
}
int	ft_echo(char *argv[])
{
	int	i;
	int	len;
	int	flag;

	i = 1;
	flag = 0;
	len = argv_len(argv);
	if (argv[1])
	{
		if (ft_strncmp("-n", argv[1], 2) == 0)
		{
			flag = 1;
			i++;
		}
		while (i < len)
		{
			printf("%s", argv[i++]);
			if (i != len)
				printf(" ");
		}
	}
	if (flag == 0)
		printf("\n");
	return (0);
}

int	ft_exit(char *argv[])
{
	int	status;
	int len;

	status = 0;
	len = argv_len(argv);
	if (len > 2)
	{
		perror("minishell: exit: too many arguments");
		return (1);
	}
	if (len == 1)
		exit(0);
	status = ft_atoi(argv[1]);
	exit(status);

}
