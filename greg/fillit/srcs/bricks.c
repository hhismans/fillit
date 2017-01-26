/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bricks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 08:07:21 by hhismans          #+#    #+#             */
/*   Updated: 2017/01/19 10:49:42 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		draw_brick(t_point *elem, char empty, char full)
{
	char	tab[NBR_COLS][NBR_LINES];
	int		i;
	int		j;

	i = 0;
	clean_tab(tab, empty);
	tab[0][0] = full;
	while (i < BRICK_SIZE)
	{
		tab[elem[i].x][elem[i].y] = full;
		i++;
	}
	i = 0;
	while (i < NBR_LINES)
	{
		j = 0;
		while (j < NBR_COLS)
		{
			ft_putchar(tab[j][i]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		draw_bricks(t_bricks *bricks)
{
	while (bricks)
	{
		draw_brick(bricks->elem, '.', '#');
		ft_putchar('\n');
		bricks = bricks->next;
	}
}

t_bricks	*new_brick(void)
{
	t_bricks *ret;

	ret = (t_bricks *)malloc(sizeof(t_bricks));
	if (!ret)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(0);
	}
	ret->next = NULL;
	return (ret);
}

t_bricks	*push_back_brick(t_bricks **bricks, t_bricks *to_push)
{
	t_bricks *tmp;

	if (*bricks)
	{
		tmp = *bricks;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_push;
	}
	else
		*bricks = to_push;
	return (*bricks);
}
