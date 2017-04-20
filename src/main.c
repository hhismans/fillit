/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:02:31 by hhismans          #+#    #+#             */
/*   Updated: 2017/04/20 19:21:10 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clean_tab(char tab[][4], char empty)
{
	int i;
	int j;

	i = 0;
	while (i < NBR_COLS)
	{
		j = 0;
		while (j < NBR_LINES)
		{
			tab[i][j] = empty;
			j++;
		}
		i++;
	}
}

void		set_point(t_point *pt, int x, int y)
{
	pt->x = x;
	pt->y = y;
}

/*
** Tu dois changer cette fonction
** j'appelle cette fonction dans le main. il faut qu'elle renvois une liste chaine de type t_bricks *
** pas grand chose a dire en plus :p.
*/

t_bricks	*init(void)
{
	t_bricks *ret;
	t_bricks *tmp;

	(void)tmp;
	ret = new_brick();
	set_point(&(ret->elem[0]), 0, 0);
	set_point(&(ret->elem[1]), 1, 0);
	set_point(&(ret->elem[2]), 1, 1);
	set_point(&(ret->elem[3]), 1, 2);

	int i = 0;
	while (i < 12)
	{
		tmp = new_brick();
		switch (i % 4){

		case 0 :
			set_point(&(tmp->elem[0]), 0, 0);
			set_point(&(tmp->elem[1]), 1, 0);
			set_point(&(tmp->elem[2]), 1, 1);
			set_point(&(tmp->elem[3]), 2, 1);
			break;
		case 1 :
			set_point(&(tmp->elem[0]), 0, 0);
			set_point(&(tmp->elem[1]), 0, 1);
			set_point(&(tmp->elem[2]), 1, 1);
			set_point(&(tmp->elem[3]), 2, 1);
			break;
		case 2 :
			set_point(&(tmp->elem[0]), 0, 0);
			set_point(&(tmp->elem[1]), 1, 0);
			set_point(&(tmp->elem[2]), 2, 0);
			set_point(&(tmp->elem[3]), 3, 0);
			break;
		case 3 :
			set_point(&(tmp->elem[0]), 0, 0);
			set_point(&(tmp->elem[1]), 1, 0);
			set_point(&(tmp->elem[2]), 1, 1);
			set_point(&(tmp->elem[3]), 1, 2);
			break;
		default :
			ft_putendl_fd("error init()", 2);
		}
		push_back_brick(&ret, tmp);
		i++;
	}
	return (ret);
}

int			lstsize(t_bricks *list)
{
	int ret;

	ret = 0;
	while (list)
	{
		list = list->next;
		ret++;
	}
	return (ret);
}

int			solve(char **map, t_bricks *bricklist, int sizemap, char brick_char)
{
	t_data pos;

	pos.x = 0;
	pos.y = 0;
	pos.forcerm = 0;
	if (!bricklist)
		return (1);
	while (pos.y < sizemap)
	{
		pos.x = 0;
		while (pos.x < sizemap)
		{
			if (fill_map(map, bricklist, brick_char, &pos))
			{
				if (solve(map, bricklist->next, sizemap, brick_char + 1))
					return (1);
				pos.forcerm = 1;
				fill_map(map, bricklist, VOID_BLOCK, &pos);
				pos.forcerm = 0;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_bricks	*bricks;
	char		**map;
	int			_size = 0;

	int size;

	size = 8; // min size, must be change by "size = sqrt_int(nbr_tetrominos);"
	bricks = init(); // init bricks, hardcode pour l'instant

	t_bricks *tmp;

	tmp = bricks;
	while (tmp)
	{
		tmp = tmp->next;
		_size++;
	}
	printf("_size = %d\n", _size);
	draw_bricks(bricks); // not needed
	map = new_map(size); // init map
	while (!solve(map, bricks, size, 'A'))
	{
		printf("current_size %d", size);
		size++; // solution not found, increase size of map
		free_map(map); // destroy map
		map = new_map(size); // recreate new map with new size
	}
	draw_map(map); // drawing solution found
	(void)argc;
	(void)argv;
	return (0);
}
