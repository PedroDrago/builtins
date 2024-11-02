#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptrc;
	int		count;

	count = 0;
	ptrc = 0;
	while (s && s[count])
	{
		if (s[count] == c)
		{
			ptrc = (char *) &s[count];
			return (ptrc);
		}
		count++;
	}
	if (s && s[count] == c)
		ptrc = (char *) &s[count];
	return (ptrc);
}
