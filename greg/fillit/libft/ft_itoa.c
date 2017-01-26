/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 07:53:46 by gfloure           #+#    #+#             */
/*   Updated: 2016/12/16 19:55:33 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrnbr(int nbr)
{
	int		nbrnbr;

	nbrnbr = 1;
	if (nbr < 0)
		nbrnbr++;
	while (nbr /= 10)
		nbrnbr++;
	return (nbrnbr);
}

char		*ft_itoa(int n)
{
	int		nbrc;
	int		neg;
	char	*s;

	nbrc = 1;
	neg = 0;
	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		neg = 1;
		nbrc++;
	}
	nbrc += ft_nbrnbr(n);
	if ((s = (char *)malloc(sizeof(char) * nbrc)) == NULL)
		return (NULL);
	s[--nbrc] = '\0';
	while (nbrc--)
	{
		s[nbrc] = n % 10 + '0';
		n = n / 10;
	}
	s[0] = (neg == 1) ? '-' : s[0];
	return (s);
}
