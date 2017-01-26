/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 04:18:43 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/26 04:24:21 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cs;
	int				i;

	i = 0;
	cs = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == cs)
			return (str + i);
		i++;
	}
	return (NULL);
}
