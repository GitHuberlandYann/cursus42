int ft_arraylen(char **array)
{
    int res;

    res = 0;
    if (!array)
        return (0);
    while (array[res])
        ++res;
    return (res);
}