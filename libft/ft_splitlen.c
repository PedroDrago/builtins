#include "libft.h"

int	ft_splitlen(char **splited)
{
	int	len;

	len = 0;
	while (splited[len++])
		;
	return (len);
}
