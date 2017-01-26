/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <gfloure>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 05:33:45 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/26 05:39:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinfree(const char *s1, const char *s2, size_t len, char c)
{
	char*s;

	s = ft_strnjoin(s1, s2, len);
	if (c == 'L' || c == 'B')
		free((char *)s1);
	if (c == 'R' || c == 'B')
		free((char *)s2);
	return (s);
}

