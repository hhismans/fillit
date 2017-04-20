/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:03:51 by hhismans          #+#    #+#             */
/*   Updated: 2017/04/20 20:45:39 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BRICK_SIZE	4
# define EXTERN_BLOCK	'!'
# define VOID_BLOCK		'.'
# define NBR_LINES	4
# define NBR_COLS		4

# define FULL '#'
# define EMPTY '.'

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"
typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_data
{
	int x;
	int y;
	int forcerm;
}				t_data;

typedef struct	s_bricks
{
	t_point			elem[BRICK_SIZE];
	struct s_bricks	*next;
}				t_bricks;

void		draw_brick(t_point *elem, char empty, char full);
void		draw_bricks(t_bricks *bricks);
t_bricks	*new_brick();
t_bricks	*push_back_brick(t_bricks **bricks, t_bricks *to_push);

void		clean_tab(char tab[][4], char empty);

void		init_map(char **map, int size);
char		**new_map(int size);
void		free_map(char **map);
void		draw_map(char **map);
void		init_map(char **map, int size);
int			fill_map(char **map, t_bricks *bricks, char filling_char,
		t_data *pos);
#endif
