/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 02:48:48 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/18 07:14:54 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_nb_block(int *parse, char *s)
{
	int		i;
	int		nb_block;

	nb_block = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == '\n') && ((s[i - 1] == '\n') || (s[i + 1] == '\0')))
			nb_block++;
		i++;
	}
	if (nb_block > MAX_TETRI)
		*parse = 1;
	return (nb_block);
}
