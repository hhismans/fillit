/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 04:55:02 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/24 19:51:32 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = s1;
	str2 = (char *)s2;
	while (*str1 != '\0')
		str1++;
	while (*str2 != '\0' && i++ < n)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (s1);
}
