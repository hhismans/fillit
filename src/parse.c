/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:50:33 by hhismans          #+#    #+#             */
/*   Updated: 2017/04/21 01:34:50 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

enum
{
	MALLOC_ERROR,
	WRONG_CHAR,
	NB_ARGS,
	LINE_SIZE,
	COLS_SIZE,
	FD_ERROR,
	NB_ELEM_IN_BRICK,
	BRICK_NOT_CONTINUE,
	UNEXPECTED_ERROR
};

void ft_error(int type)
{
	if (type == MALLOC_ERROR)
		ft_putstr_fd("Malloc error\n", 2);
	else if (type == WRONG_CHAR)
		ft_putstr_fd("Wrong char error, check your file\n", 2);
	else if (type == LINE_SIZE)
		ft_putstr_fd("Wrong number of args, use 1 path\n", 2);
	else if (type == COLS_SIZE)
		ft_putstr_fd("col size error, verify file\n", 2);
	else if (type == NB_ARGS)
		ft_putstr_fd("Line size, verify file\n", 2);
	else if (type == FD_ERROR)
		ft_putstr_fd("verify file path, no fd found\n", 2);
	else if (type == NB_ELEM_IN_BRICK)
		ft_putstr_fd("There is too much (or not enough) piece to form a tetrominos\n", 2);
	else if (type == BRICK_NOT_CONTINUE)
		ft_putstr_fd("tetrominos isn't in one piece\n", 2);
	else if (type == UNEXPECTED_ERROR)
		ft_putstr_fd("Unexpected error, this error shouldn't be triggered, please review the code\n", 2);
	exit(0);
}

int nb_elem_in_brick(char **brick)
{
	int i;
	int j;
	int nb;

	i = 0;
	nb = 0;

	while (brick[i])
	{
		j = 0;
		while (brick[i][j])
		{
			if (brick[i][j] == FULL)
				nb++;
			else if (brick[i][j] != EMPTY && brick[i][j] != '\n')
				ft_error(WRONG_CHAR);
			j++;
		}
		if (j > 4)
			ft_error(LINE_SIZE);
		i++;
	}
	if (i > 4)
		ft_error(COLS_SIZE);
	return (nb);
}

int points_are_adjacent(t_point p1, t_point p2)
{
	int ret;

	ret = (p1.x == p2.x && ((p1.y + 1) == p2.y || (p1.y - 1) == p2.y))
			||
			(p1.y == p2.y && ((p1.x + 1) == p2.x || (p1.x - 1) == p2.x));
	return (ret);
}

/*
** NAME			:	vice cartel to the top
** DESCRIPTION	:	pasltemps de niaiser
** INPUT		:	tequila, heineken
** RETURN VALUE	:	toutltin toutltin toutltin
** 
** ndlr: vice cartel == tetrominos
*/
void vice_cartel_to_the_top_left(t_bricks *brick)
{
	int offsetx;
	int offsety;
	int i;

	offsetx = brick->elem[0].x;
	offsety = brick->elem[0].y;
	i = 0;
	while (i < BRICK_SIZE)
	{
		brick->elem[i].x -= offsetx;
		brick->elem[i].y -= offsety;
		i++;
	}
}

int check_points(t_point points[])
{
	int i;
	int j;
	int nb_of_link;

	i = 0;
	while (i < 4)
	{
		nb_of_link = 0;
		j = i + 1;
		while (j < 4)
		{
			if (points_are_adjacent(points[i], points[j]))
				nb_of_link++;
			j++;
		}
		i++;
	}
	return (nb_of_link >= 3);
}

int check_continuity(char **brick)
{
	int i;
	int j;
	int p;
	t_point point[4];

	p = 0;
	i = 0;
	while (brick[i])
	{
		j = 0;
		while (brick[i][j])
		{
			if (brick[i][j] == FULL)
				point[p].x = j;
				point[p].y = i;
			j++;
		}
		i++;
	}
	if (p != 3)
		ft_error(BRICK_NOT_CONTINUE);
	return (check_points(point));
}

int check_brick(char **bricks)
{
	if (nb_elem_in_brick(bricks) != 4)
		ft_error(NB_ELEM_IN_BRICK);
	return (1);
}

/*
** WARNING USE MALLOC HERE
*/
t_bricks *strings_to_bricks(char **string_bricks)
{
	t_bricks *bricks;
	int i;
	int j;
	int elem_i;

	bricks = new_brick();
	i = 0;
	elem_i = 0;
	while (string_bricks[i])
	{
		j = 0;
		while (string_bricks[i][j])
		{
			if (string_bricks[i][j] == FULL)
			{
				set_point(&(bricks->elem[elem_i]), j, i);
				elem_i++;
				if (elem_i > BRICK_SIZE)
					ft_error(UNEXPECTED_ERROR);
			}
			j++;
		}
		i++;
	}
	return (bricks);
}

/*
** custum version, dont use it in genreal
*/
char **get_next_lines(int fd, int nb_lines)
{
	int		i;
	int		c_read;
	char	**ret;
	char	*buf;

	ret = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < nb_lines)
	{
		c_read = get_next_line(fd, &buf);
		if (c_read == 0)
			break;
		ret[i] = ft_strdup(buf);
		free(buf);
		i++;
	}
	if (c_read != 0)
		ret[nb_lines] = NULL;
	else
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}

t_bricks *get_next_brick(const int fd)
{
	t_bricks *ret;
	char **bricks_strings;

	bricks_strings = get_next_lines(fd, 4);
	ret = NULL;
	if (bricks_strings)
	{
		check_brick(bricks_strings);
		ret = strings_to_bricks(bricks_strings);
	}
	return (ret);
}

t_bricks *get_bricks_from_file(char *path)
{
	int			fd;
	t_bricks	*brickslist;
	t_bricks	*tmp;
	char *str;

	brickslist = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(FD_ERROR);
	while ((tmp = get_next_brick(fd)))
	{
		get_next_line(fd, &str);
		vice_cartel_to_the_top_left(tmp);
		push_back_brick(&brickslist, tmp);
	}
	return (brickslist);
}
