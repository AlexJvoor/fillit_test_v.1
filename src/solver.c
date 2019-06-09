/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:19:58 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 21:19:03 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					*fillcoord(char *temp, int number)
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
			coord[j++] = (i / 5) * 10 + i % 5;
		i++;
	}
	coord[j] = number;
	return (coord);
}

int					**fill_tetr(char *buff, int kolvo)
{
	int				**tetr;
	char			*temp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!(tetr = (int **)malloc(sizeof(int *) * kolvo + 1)))
		return (NULL);
	while (++i < kolvo)
		tetr[i] = ft_memalloc(6);
	while (kolvo--)
	{
		temp = ft_strnew(21);
		temp = ft_strsub(buff, i, 21);
		i += 21;
		tetr[j] = fillcoord(temp, j);
		j++;
		ft_memdel((void **)&temp);
	}
	return (tetr);
}

int				solve(char *buff, int kolvo)
{
	int		**tetr;

	tetr = fill_tetr(buff, kolvo);
	return (0);
}
