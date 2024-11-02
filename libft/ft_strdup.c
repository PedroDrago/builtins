#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		count;

	ret = (char *) malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	count = 0;
	while (s[count])
	{
		ret[count] = s[count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
