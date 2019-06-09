/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 02:12:38 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/09 02:12:39 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			delmap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}

static	void	deltetri(t_tetri *tetri)
{
	int y;

	y = 0;
	while (y < tetri->height)
	{
		ft_memdel((void **)(&tetri->coord[y]));
		y++;
	}
	ft_memdel((void **)(&tetri->coord));
	ft_memdel((void **)&tetri);
}

void			deltetriminos(t_list *tetriminos)
{
	t_tetri		*tetri;
	t_list		*next;

	while (tetriminos != NULL)
	{
		tetri = (t_tetri *)tetriminos->content;
		next = tetriminos->next;
		deltetri(tetri);
		ft_memdel((void **)&tetriminos);
		tetriminos = next;
	}
}

void			free_fillit(t_map *field, t_list *tetriminos)
{
	delmap(field);
	deltetriminos(tetriminos);
}