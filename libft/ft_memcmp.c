#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	count;

	count = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (count < n)
	{
		if (ptr1[count] != ptr2[count])
			return ((unsigned char)ptr1[count] - (unsigned char)ptr2[count]);
		count++;
	}
	return (0);
}
