/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:53:29 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/26 05:58:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EXTERN_BLOCK '!'
#define VOID_BLOCK '.'
#define NBR_LINES 4
#define NBR_COLS 4
#define MAX 1024 
#define FILL '#'
#define EMPTY '.'
#define BRICK_SIZE 4
#define MAX_TETRI 26

typedef struct		s_vector
{
	int				x;
	int				y;
	int				w;
}					t_vector;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_bricks
{
	t_point			elem[BRICK_SIZE];
	struct s_bricks	*next;
}					t_bricks;

typedef struct		s_data
{
	int				x;
	int				y;
	int				forcerm;
}					t_data;

void	draw_brick(t_point *elem, char empty, char full);
void	draw_bricks(t_bricks *bricks);
t_bricks *init(char *s);
t_bricks *new_brick();
t_bricks *get_bricks(char *s, t_vector min, t_vector max);
t_bricks *push_back_brick(t_bricks **bricks, t_bricks *to_push);
void	clean_tab(char tab[][4], char empty);
void	init_map(char **map, int size);
char	**new_map(int size);
void	free_map(char **map);
void	draw_map(char **map);
void	init_map(char **map, int size);
int		fill_map(char **map, t_bricks *bricks, char filling_char, t_data pos);
void	ft_error(int i);
void	ft_check_map(int *parse, char *str);
void	ft_read(char *argv);
void	ft_valid_char(int *parse, char *str);
int		ft_nb_block(int *parse, char *s);
int		ft_nb_sharp(int *parse, char *s, int len);
void	ft_check_len(int *parse, char *str);
void	ft_check_chariot(int *parse, char *str);
int		**ft_fill_tab(char *s, int len);
int		**ft_malloc_tab(int len);
int		check_all_tetris(int **t, int len);

#endif
