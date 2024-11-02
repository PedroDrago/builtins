#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char) s1[count]) == ((unsigned char) s2[count]))
		&& (s1[count]) && (s2[count]) && (--n))
		count++;
	return ((unsigned char) s1[count] - (unsigned char) s2[count]);
}
