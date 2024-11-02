#include "libft.h"

void	free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i]);
	free(splited);
}
