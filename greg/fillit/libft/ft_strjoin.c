/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 07:52:56 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/29 14:13:44 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strcpy(newstr, s1);
	ft_strcat(newstr, s2);
	return (newstr);
}
