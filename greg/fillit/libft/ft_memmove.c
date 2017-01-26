/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 07:37:25 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/30 05:54:29 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * n);
	if (tmp)
	{
		ft_memcpy(tmp, s2, n);
		ft_memcpy(s1, tmp, n);
		free(tmp);
	}
	return (s1);
}
