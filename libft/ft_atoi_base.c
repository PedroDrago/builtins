#include "libft.h"

static int	find_pos(char c, int base, const char *charset)
{
	int	count;

	count = 0;
	while (count < base)
	{
		if (charset[count] == c)
			return (count);
		count++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base, const char *charset)
{
	int	count;
	int	sign;
	int	pos;
	int	atoi;

	count = 0;
	atoi = 0;
	sign = 1;
	if (str[0] == '-')
	{
		str++;
		sign = -1;
	}
	while (str[count] >= charset[0] && str[count] <= charset[base - 1])
	{
		pos = find_pos(str[count++], base, charset);
		if (pos < 0)
			return (atoi);
		atoi = atoi * base + pos;
	}
	return (atoi * sign);
}
