#include "libft.h"
#include <stdio.h>

static int	concatenate_s1(char const *s1, char *joined)
{
	int	count;

	count = 0;
	if (!s1)
		return (0);
	while (s1[count])
	{
		joined[count] = s1[count];
		count++;
	}
	return (count);
}

static void	concatenate_s2(char const *s2, int i, char *joined)
{
	int	count2;

	if (!s2)
		return ;
	count2 = 0;
	while (s2[count2])
	{
		joined[i] = s2[count2];
		i++;
		count2++;
	}
	joined[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = concatenate_s1(s1, joined);
	concatenate_s2(s2, i, joined);
	return (joined);
}
