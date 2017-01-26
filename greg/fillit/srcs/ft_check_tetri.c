/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:22:14 by hhismans          #+#    #+#             */
/*   Updated: 2017/01/18 08:59:11 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fillit.h"

int		check_tetris(int *t)
{
	int	i;
	int	linked;
	int a;

	i = -1;
	a = 0;
	while (++i < 15)
	{
		linked = 0;
		if (t[i])
		{
			if ((i >= 1 && t[i - 1]))
				++linked;
			if (t[i +1])
				++linked;
			if (i <= 12 && t[i + 4])
				++linked;
			if (i >= 4 && t[i - 4])
				++linked;
			(linked == 2) ? ++a : 0;
			if (a == 2 || linked == 3)
				return (0);
		}
	}
	return (1);
}


int		check_all_tetris(int **t, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (check_tetris(t[i]))
			return (0);
	return (1);
}
