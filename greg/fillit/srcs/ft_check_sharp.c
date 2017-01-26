/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sharp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 04:02:22 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/20 03:07:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_nb_sharp(int *parse, char *s, int len)
{
	int		i;
	int		sharp;

	sharp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == FILL)
			sharp++;
		i++;
	}
	if ((len * 4) != sharp)
		*parse = 1;
	return (sharp);
}
