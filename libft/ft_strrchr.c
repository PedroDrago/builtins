char	*ft_strrchr(const char *s, int c)
{
	char	*ptrc;
	int		count;

	count = 0;
	ptrc = 0;
	while (s[count])
	{
		if (s[count] == c)
			ptrc = (char *) &s[count];
		count++;
	}
	if (s[count] == c)
		ptrc = (char *) &s[count];
	return (ptrc);
}
