long	ft_atol(const char *nptr)
{
	long	number;
	int		sign;
	int		count;

	number = 0;
	sign = 1;
	count = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || (nptr[count] == 32))
		count++;
	if (nptr[count] == '-')
		sign = -1;
	if (nptr[count] == '-' || nptr[count] == '+')
		count++;
	while (nptr[count] >= '0' && nptr[count] <= '9')
		number = number * 10 + (nptr[count++] - '0');
	return (number * sign);
}
