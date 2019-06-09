/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:19:58 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 22:42:54 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		square(int count)
{
	int				n;

	n = 2;
	while (count * 4 < n * n)
		n++;
	return (n);
}

static t_map		*get_map(int size)
{
	t_map			*new;
	int				i;
	int				j;

	i = 0;
	new = (t_map *)ft_memalloc(sizeof(t_map));
	new->map = (char **)ft_memalloc(sizeof(char *) * size);
	while (i < size)
	{
		j = 0;
		new->map[i] = (char *)ft_memalloc(size + 1);
		while (j < size)
		{
			new->map[i][j] = '.';
			j++;
		}
		i++;
	}
	new->size = size;
	return (new);
}

t_map			*solve(t_list *tetriminos)
{
	t_map		*map;
	int			size;

	size = square(ft_lstcount(tetriminos));
	map = get_map(size);
	while (!(fill_field(map, tetriminos)))
	{
		size = size + 1;
		delmap(map);
		map = get_map(size);
	}
	return (map);
}