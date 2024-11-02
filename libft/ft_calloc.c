#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocation;

	if (nmemb == 0 || size == 0)
	{
		allocation = malloc (1);
		return (allocation);
	}
	allocation = malloc (nmemb * size);
	if (!allocation)
		return (NULL);
	ft_bzero(allocation, (nmemb * size));
	return (allocation);
}
