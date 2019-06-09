/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:27:55 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 21:14:48 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		kolvo;
    char    *buff;
    int     fd;

	if (argc != 2)
		return (end("usage ./fillit [map]"));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (end("error"));
	buff = ft_memalloc(546);
    if ((read(fd, buff, 546) < 0))
		return (end("error"));
	if ((kolvo = is_valid(buff)) < 0)
		return (end("error"));
	if (!(solve(buff, kolvo)))
		return (end("error"));
	return (0);   
}
