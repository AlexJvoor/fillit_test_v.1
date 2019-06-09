/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:11:44 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 21:31:11 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "libft.h"

int		f_s(int c_tr);
char	**try2fill(char **nfield, int *atr, int i, int j);
int		**put_tr(char **field, int *atr);
char		**fill_field(char **atr, int c_tr, int extra);
void	output(char **field);
int		main(int argc, char **argv);
int					end(char *str);
int					*fillcoord(char *temp, int number);
int					**fill_tetr(char *buff, int kolvo);
int				solve(char *buff, int kolvo);
int					bond(char *buff, int figure);
int					is_valid(char *buff);


#endif
