int		f_s(int c_tr)
{
	int		n;

	n = 2;
	while (c_tr * 4 < n * n)
		n++;
	return (n);
}

char	**try2fill(char **nfield, int *atr, int i, int j)
{
	char	**nnfield;
	int		k;
	int		ch;

	k = 0;
	ch = atr[k];
	nnfield = nfield;
	nnfield[i][j] = (atr[4] + 'A')
	while (k < 3)
	{
		ch = atr[++k] - ch;
		i += (ch / 10);
		j += (ch % 10);
		if (nnfield[i][j] == '0')
			nnfield[i][j] = (atr[4] + 'A');
		else
			return (NULL);
	}
	return (nnfield);
}

int		**put_tr(char **field, int *atr)
{
	char 	**nfield;
	int		i;
	int		j;

	j = -1;
	i = -1;
	nfield = field;
	while (nfield[++i])
		while (nfield[i][++j] != '\n')
			if ((nfield[i][j] == '0') && (nfield = try2fill(nfield, atr, i, j)))
				return (nfield);
}

char		**fill_field(char **atr, int c_tr, int extra)//extra == 0
{
	char	**field;
	int		i;
	int		n;

	n = f_s(c_tr) + extra;
	i = -1
	while (++i < n)
		field[i] = ft_strnew((size_t)n);
	field[i] = NULL;
	i = -1
	while (atr[++i] != NULL)
		if (field = put_tr(field, atr[i]) == NULL)
			return (fill_field(atr, c_tr, ++extra));
	return (field);
}

