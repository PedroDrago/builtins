#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr_s;
	size_t	count;

	ptr_s = (char *) s;
	count = 0;
	while (count < n)
	{
		if (ptr_s[count] == c)
			return ((void *) s + count);
		count++;
	}
	return (NULL);
}
