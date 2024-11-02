#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*ptr;

	ptr = (char *) s;
	count = -1;
	while (++count < n)
		ptr[count] = 0;
}
