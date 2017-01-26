/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 03:59:44 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/30 12:10:31 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	if (n != 0)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
			return (s1 + 1);
		return (ft_memccpy(s1 + 1, s2 + 1, c, --n));
	}
	return (NULL);
}
