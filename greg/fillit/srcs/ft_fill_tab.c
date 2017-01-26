/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 03:44:14 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/18 07:30:02 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		**ft_fill_tab(char *s, int len)
{
	int			**tab;
	t_vector	v;

	if (!(tab = ft_malloc_tab(len)))
		return (NULL);
	v.y = -1;
	v.w = 0;
	while (++v.y < len)
	{
		v.x = 0;
		while (v.x < 16)
		{
			while (s[v.w] == '\n')
				v.w++;
			tab[v.y][v.x] = (s[v.w] == '#') ? 1 : 0;
			v.x++;
			v.w++;
		}
	}
	return (tab);
}
