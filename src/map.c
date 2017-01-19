/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:38:19 by hhismans          #+#    #+#             */
/*   Updated: 2017/01/19 10:54:02 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** we add BRICK_SIZE to have extra layers on the map, this required more
** memory, but we will never use wrong index with this way
**
** map example :
** !!!!!!!!!!!!!!!!!!!
** !!!!!!!!!!!!!!!!!!!
** !!!!!!!!!!!!!!!!!!!
** !!!!!!!!!!!!!!!!!!!
** !!!!...........!!!!
** !!!!...........!!!!
** [...]
** !!!!...........!!!!
** !!!!!!!!!!!!!!!!!!!
** !!!!!!!!!!!!!!!!!!!
** !!!!!!!!!!!!!!!!!!!
** !!!!!!!!!!!!!!!!!!!
*/

char	**new_map(int size)
{
	char	**ret;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (size + BRICK_SIZE * 2 + 1));
	if (!ret)
	{
		ft_putendl_fd("malloc error\n", 2);
		exit(0);
	}
	i = 0;
	while (i < size + BRICK_SIZE * 2 + 1)
	{
		ret[i] = (char *)malloc(sizeof(char) * (size + BRICK_SIZE * 2 + 1));
		if (!ret[i])
		{
			ft_putendl_fd("malloc error\n", 2);
			exit(0);
		}
		i++;
	}
	init_map(ret, size);
	return (ret);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	draw_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '!')
				ft_putchar(map[i][j]);
			j++;
		}
		if (map[i][j / 2] != '!')
			ft_putchar('\n');
		i++;
	}
}

void	init_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size + BRICK_SIZE * 2)
	{
		j = 0;
		while (j < size + BRICK_SIZE * 2)
		{
			if (i < BRICK_SIZE || j < BRICK_SIZE ||
					j > size + BRICK_SIZE - 1 || i > size + BRICK_SIZE - 1)
				map[i][j] = EXTERN_BLOCK;
			else
				map[i][j] = VOID_BLOCK;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

/*
** WARNING ! weird stuff around here hohoho
** return 0 if failed, nothing change on map if failed
** return 1 if all is fine
*/

int		fill_map(char **map, t_bricks *bricks, char filling_char, t_data pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[(BRICK_SIZE) + pos.y + bricks->elem[i].y]
				[(BRICK_SIZE) + pos.x + bricks->elem[i].x] == VOID_BLOCK
				|| pos.forcerm)
			map[(BRICK_SIZE) + pos.y + bricks->elem[i].y]
				[(BRICK_SIZE) + pos.x + bricks->elem[i].x] = filling_char;
		else
		{
			while (--i >= 0)
				map[(BRICK_SIZE) + pos.y + bricks->elem[i].y]
					[(BRICK_SIZE) + pos.x + bricks->elem[i].x] = VOID_BLOCK;
			return (0);
		}
		i++;
	}
	return (1);
}
