#include "libft.h"

void	ft_strlower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}
