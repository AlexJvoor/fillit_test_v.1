void	output(char **field)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (field[++i] != NULL)
	{
		ft_putstr(field[i]);
		ft_putchar('\n');
	}
}