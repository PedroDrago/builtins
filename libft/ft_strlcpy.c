#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*end;
	const char	*start;

	if (size == 0)
		return (ft_strlen(src));
	end = dst + size;
	start = src;
	while (*start != '\0' && dst < end)
	{
		*dst = *start;
		dst++;
		start++;
	}
	if (dst < end)
		*dst = 0;
	else if (size > 0)
		dst[-1] = 0;
	while (*start != '\0')
		start++;
	return (ft_strlen(src));
}
