/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 01:13:58 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/09 01:14:00 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int					get_height(char *temp)
{
	int 					i;
	int						min;
	int 					max;

	i = 0;
	max = 0;
	min = 3;
	while (i < 20)
	{
		if (temp[i] == '#')
		{
			if (i / 5 < min)
				min = i / 5;
			if (i / 5 > max)
				max = i / 5;
		}
		i++;
	}
	return (max - min + 1);
}

static int					get_width(char *temp)
{
	int 					i;
	int						min;
	int 					max;

	i = 0;
	max = 0;
	min = 3;
	while (i < 20)
	{
		if (temp[i] == '#')
		{
			if (i % 5 < min)
				min = i % 5;
			if (i % 5 > max)
				max = i % 5;
		}
		i++;
	}
	return (max - min + 1);
}

static int					*get_coord(char *temp)
{
	int				i;
	int				j;
	int				*coord;

	i = 0;
	j = 0;
	if(!(coord = (int *)malloc(sizeof(int) * 4 + 1)))
		return (NULL);
	while (temp[i])
	{
		if (temp[i] == '#')
		{
			coord[j] = (i / 5) * 10 + i % 5;
			j++;
		}
		i++;
	}
	return (coord);
}

static t_tetri			*get_tetri(char *temp, char sym)
{
	t_tetri		*tetri;

	tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri *));
	tetri->symbol = sym;
	tetri->coord = get_coord(temp);
	tetri->height = get_height(temp);
	tetri->width = get_width(temp);
	return (tetri);
}

t_list			*start(char *buff)
{
	t_list		*tetriminos = NULL;
	t_tetri 	*tetri;
	char		*temp;
	char		sym;
	int			i;

	i = 0;
	sym = 'A';
	while (i <= (int)ft_strlen(buff))
	{
		temp = ft_strsub(buff, i, 21);
		if ((tetri = get_tetri(temp, sym++)) == NULL)
		{
			ft_memdel((void **)&temp);
			deltetriminos(tetriminos);
			return (NULL);
		}
		ft_lstend(&tetriminos, ft_lstnew(tetri, sizeof(tetri)));
		ft_memdel((void **)&temp);
		ft_memdel((void **)&tetri);
		i +=21;
	}
	ft_memdel((void **)&temp);
	return (tetriminos);
}