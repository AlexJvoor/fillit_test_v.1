/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:27:55 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 22:30:25 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int argc, char **argv)
{
	t_map			*map;
	t_list			*tetriminos = NULL;
  	char 			buff[552];
	int				fd;

	if (argc != 2)
		return (end("usage ./fillit [map]"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 551) < 0) || !buff[0])
		return (end("error"));
	if ((is_valid(buff)) == 0)
		tetriminos = start(buff);
	else
		return (end("error"));
	map = solve(tetriminos);
	output(map);
	free_fillit(map, tetriminos);
	return (0);   
}