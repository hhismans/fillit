/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 05:32:22 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/24 19:40:36 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	char	b;

	i = 0;
	nbr = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\r') ||
	(str[i] == '\f' || str[i] == '\v' || str[i] == '\b' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		b = str[i];
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - 48;
		i++;
	}
	if (b == '-')
		return (-nbr);
	else
		return (nbr);
}
