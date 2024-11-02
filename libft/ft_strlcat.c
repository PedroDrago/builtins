#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[count] && count < size)
		count++;
	while (src[count2] && (count + count2 + 1) < size)
	{
		dst[count + count2] = src[count2];
		count2++;
	}
	if (count < size)
		dst[count + count2] = '\0';
	return (count + ft_strlen(src));
}
