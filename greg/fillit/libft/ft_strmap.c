/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 07:48:34 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/14 16:10:36 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(d = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		d[i] = (*f)(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
