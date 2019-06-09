/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:18:38 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 19:19:16 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				output(t_map *map)
{
	int				i;

	i = -1;
	while (map->map[++i] != NULL)
		ft_putendl((char *)(map->map[i]));
}

int					end(char *str)
{
	ft_putendl(str);
	return (0);
}
