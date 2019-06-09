/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:33:50 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 22:42:11 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char	**try2fill(char **nfield, int *atr, int i, int j)
// {
// 	char	**nnfield;
// 	int		k;
// 	int		ch;

// 	k = 0;
// 	ch = atr[k];
// 	nnfield = nfield;
// 	nnfield[i][j] = (atr[4] + 'A');
// 	while (k < 3)
// 	{
// 		ch = atr[++k] - ch;
// 		i += (ch / 10);
// 		j += (ch % 10);
// 		if (nnfield[i][j] == '.')
// 			nnfield[i][j] = (atr[4] + 'A');
// 		else
// 			return (nfield);
// 	}
// 	return (nnfield);
// }

// char		**put_tr(char **field, t_tetri *tetri)
// {
// 	char	**nfield;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	nfield = field;
// 	while (nfield[++i])
// 	{
// 		j = -1;
// 		while (nfield[i][++j] != '\0')
// 			if ((nfield[i][j] == '.') && (nfield = try2fill(nfield, atr, i, j)))
// 				return (nfield);
// 	}
// 	return (NULL);
// }

static	void	put_tetri(t_map *field, t_tetri *tetri, char symbol)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if ((tetri->coord[c] / 10 ) == j && (tetri->coord[c] % 10) == i && c++)
				field->map[field->y + j][field->x + i] = symbol;
			j++;
		}
		i++;
	}
}

static	int		try_to_fill(t_map *field, t_tetri *tetri)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if ((tetri->coord[c] / 10 == j) && (tetri->coord[c] % 10) == i && field->map[field->y + j][field->x + i] != '.' && c++)
				return (0);
			j++;
		}
		i++;
	}
	put_tetri(field, tetri, tetri->symbol);
	return (1);
}

int				fill_field(t_map *field, t_list *tetriminos)
{
	t_tetri		*check;
	int		i;
	int		j;

	if (tetriminos == NULL)
		return (1);
	check = (t_tetri *)(tetriminos->content);
	i = 0;
	while (i < field->size - check->height + 1)
	{
		j = 0;
		while (j < field->size - check->width + 1)
		{
			field->x = i;
			field->y = j;
			if (try_to_fill(field, check) == 1)
			{
					if (fill_field(field, tetriminos->next))
						return (1);
					else
						put_tetri(field, check, '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}
