/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:44:47 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/30 12:10:20 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	int			i;
	char		*des;
	const char	*sr;

	i = 0;
	des = (char *)s1;
	sr = (char *)s2;
	while (i < (int)n)
	{
		des[i] = sr[i];
		i++;
	}
	return (s1);
}
