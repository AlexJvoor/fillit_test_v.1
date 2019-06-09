/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:16:35 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/08 20:32:47 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					bond(char *buff, int figure)
{
	int				i;
	int				sharp;

	i = -1;
	sharp = 0;
	while (buff[++i] != '\0')
	{
		if (buff[i] == '#')
			if (buff[i + 1] == '#' || ((i + 1) % 21 < 15 && buff[i + 5] == '#'))
				sharp++;
		if ((i + 1) % 21 == 0)
		{
			if (!(sharp >= 3))
				return (-1);
			sharp = 0;
		}
	}
	return (figure);
}

int					is_valid(char *buff)
{
	int				i;
	int				sharp;

	sharp = 0;
	i = -1;
	while (buff[++i] != '\0')
	{
		if (i % 5 < 4)
		{
			if (buff[i] == '\n' && ((i + 1) % 21 == 0))
				continue;
			if (!(buff[i] == '#' || buff[i] == '.'))
				return (-1);
			if (buff[i] == '#' && ++sharp > 4)
				return (-1);
		}
		else if (buff[i] != '\n')
			return (-1);
	}
	if (buff[i - 1] == '\n' && buff[i - 2] == '\n')
		return (-1);
	if (((i + 1) % 21) == 0)
		return (bond(buff, (i + 1) / 21));
	return (-1);
}
