#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	count;

	count = 0;
	map = (char *) malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!map)
		return (NULL);
	while (s[count])
	{
		map[count] = f(count, s[count]);
		count++;
	}
	map[count] = '\0';
	return (map);
}
