/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_chariot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 00:41:40 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/18 07:15:23 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_check_chariot(int *parse, char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j++;
			if (j == 5)
			{
				if (str[i - 1] != '\n')
					*parse = 1;
				j = 0;
			}
		}
		i++;
	}
}
