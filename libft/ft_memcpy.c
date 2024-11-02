#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	char			*ptr_dest;
	const char		*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (char *) dest;
	ptr_src = (const char *) src;
	count = -1;
	while (++count < n)
		ptr_dest[count] = ptr_src[count];
	return (dest);
}
