/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:56:13 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/26 05:03:27 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (*s1 && n)
	{
		if (*s1 == s2[i])
			i++;
		else
			i = 0;
		if (s2[i] == '\0')
			return ((char *)(s1 - i + 1));
		s1++;
		n--;
	}
	return (NULL);
}
