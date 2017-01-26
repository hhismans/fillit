/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 00:30:42 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/18 07:22:15 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		**ft_malloc_tab(int len)
{
	int		**tab;
	int		y;

	if (!(tab = (int **)malloc(sizeof(int *) * len)))
		return (NULL);
	y = -1;
	while (++y < len)
	{
		if (!(tab[y] = (int *)malloc(sizeof(int) * 16)))
			return (NULL);
	}
	return (tab);
}
