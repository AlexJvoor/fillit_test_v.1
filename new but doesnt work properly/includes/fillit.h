/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:11:44 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 22:30:38 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_map
{
	int		size;
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef struct	s_tetri
{
	int			*coord;
	char		symbol;
	int			height;
	int			width;
}				t_tetri;

int				main(int argc, char **argv);
int				end(char *str);
int				is_valid(char *buff);
t_list			*start(char *buff);
t_map			*solve(t_list *tetriminos);
int				fill_field(t_map *field, t_list *tetriminos);
void			output(t_map *map);
void			delmap(t_map *map);
void			deltetriminos(t_list *tetriminos);
void			free_fillit(t_map *map, t_list *tetriminos);


#endif
