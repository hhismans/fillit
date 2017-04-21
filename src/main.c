/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:02:31 by hhismans          #+#    #+#             */
/*   Updated: 2017/04/21 01:59:44 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			sqrt_int(int nb)
{
	int ret;

	ret = 0;
	while (ret * ret != nb && ret < INT_MAX)
		ret++;
	return (ret);
}

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

/*
** NAME			:	SOLVE
**
** DESCRIPTION	:	Fill map with a solution if there's one
**
** INPUT		:	map is just a char **tab which is already alocated
**
** 					bricklist is a list of brick (tetrominos). see fillit.h to struct data
** 					example of brick with 4 point "elem" (cf fillit.h)
** 						brick.elem[0].x = 0		represent:
** 						brick.elem[0].y = 0		#...	//elem[0] coord (x;y) = (0;0)
** 						brick.elem[1].x = 1		.#..	//elem[1] coord (x;y) = (1;1)
** 						brick.elem[1].y = 1		..#.	//elem[2] coord (x;y) = (2;2)
** 						brick.elem[2].x = 2		....
** 						brick.elem[2].y = 2
** 					...which is invalid but it's for the example :D
**
** 					-size map, obviously, the actual size of the map

**RETURN VALUE	:	1 if a solution if found, map is fill with solution
**					0 if not, map content is undetermined
**
**	pro tips recursive function ftw
*/
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

	bricks = get_bricks_from_file(argv[1]);

	size = sqrt_int(lstsize(bricks) * 4); // min size, must be change by "size = sqrt_int(nbr_tetrominos);"
	map = new_map(size); // init map
	while (!solve(map, bricks, size, 'A'))
	{
		size++; // solution not found, increase size of map
		free_map(map); // destroy map
		map = new_map(size); // recreate new map with new size
	}
	draw_map(map); // drawing solution found
	return (0);
}
