/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 02:39:07 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/26 05:15:53 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	if ((s = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
