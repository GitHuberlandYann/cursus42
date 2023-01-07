int	ft_arraylen(char **array)
{
	int	res;

	if (!array)
		return (0);
	res = 0;
	while (array[res])
		++res;
	return (res);
}
