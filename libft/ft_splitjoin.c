#include "libft.h"

static int	count_split_chars(char **splited)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	*ft_splitjoin(char **splited)
{
	char	*joined;
	int		i;
	int		j;
	int		x;

	joined = malloc(sizeof(char) * (count_split_chars(splited) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	x = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
			joined[x++] = splited[i][j++];
		i++;
	}
	joined[x] = '\0';
	return (joined);
}
