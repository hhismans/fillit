/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:02:31 by hhismans          #+#    #+#             */
/*   Updated: 2017/01/26 05:57:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

t_bricks	*init(char *s)
{
	t_vector		min;
	t_vector		max;
	int				i;
	int				a;

	min.y = -1;
	min.x = 4;
	a = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			++a;
			if (min.y == -1)
				min.y = i / 4;
			if (min.x <= i % 4)
				min.x = i % 4;
			if (a == 4)
				max.y = i / 4;
			if (a < 4 && (i % 4 >= max.x))
				max.x = i % 4;
		}
	}
	get_bricks(s, min, max);
}

t_bricks	*get_bricks(char *s, t_vector min, t_vector max)
{
	t_bricks	*tmp;
	t_bricks	*ret;
	int			i;
	int			a;

	i = 0;
	a = 0;
	ret = new_brick();
	while (a < 3)
	{
		tmp = new_brick();
		if (i % 4 >= min.x && i % 4 <= max.x && i / 4 >= min.y && i / 4 <= max.y
				&& s[i] == '#')
		{
			set_point(&(tmp->elem[a]), i / 4 - min.y, i % 4 - min.x);
			++a;
		}
		++i;
	}
	push_back_brick(&ret, tmp);
	return (ret);
}
/*

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
   return (ret);*/

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
		if (brick_char == 'A')
			printf("\t%d percent done\n", pos.y * 100 / sizemap);
		while (pos.x < sizemap)
		{
			if (fill_map(map, bricklist, brick_char, pos))
			{
				if (solve(map, bricklist->next, sizemap, brick_char + 1))
					return (1);
				pos.forcerm = 1;
				fill_map(map, bricklist, VOID_BLOCK, pos);
				pos.forcerm = 0;
			}
			pos.x++;
			if (brick_char == 'A')
				printf("\t\t %d percent row done\n", pos.x * 100 / sizemap);
		}
		pos.y++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_bricks	*bricks;
	char		**map;
	int			size;

	size = 7; // min size, must be change by "size = sqrt_int(nbr_tetrominos);"
	bricks = init(); // init bricks, hardcode pour l'instant
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
