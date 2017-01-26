/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:33:11 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/20 01:20:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"


static void	ft_print_tetris(int len, int **tab)
{
	int		i;
	int		j;
	j = 0;
	while (j < len)
	{
		i = -1;
		while (++i < 16)
		{
			ft_putnbr(tab[j][i]);
			if (i % 4 == 3)
			ft_putchar('\n');
		}
		ft_putchar('\n');
		++j;
	}
}

void	ft_read(char *argv)
{
	int		fd;
	int		res_read;
	char	buf[MAX + 1];
	int		parse;
	int		len;
	int	**tab;
	
	parse = 0;

	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_error(0);
	if ((res_read = (read(fd, buf, MAX))) == -1)
		ft_error(0);

	len = ft_nb_block(&parse, buf);
	tab = ft_fill_tab(buf, len);
//	ft_putstr(buf);
	ft_print_tetris(len, tab);//debug
	ft_check_chariot(&parse, buf);
	ft_check_len(&parse, buf);
	ft_valid_char(&parse, buf);
	ft_nb_sharp(&parse, buf, len);
	ft_nb_block(&parse, buf);
	if (!check_all_tetris(tab, len))
		ft_error(0);
	if (parse)
		ft_error(0);



}
