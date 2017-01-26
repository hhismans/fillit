/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 07:53:13 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/14 17:01:00 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_whitelen(char const *s)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		if (s[i] == '\0')
			return (0);
	}
	while (s[i] != '\0')
	{
		i++;
		j++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		j--;
	}
	return (j);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_whitelen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!(str = ft_strsub(s, i, len)))
		return (NULL);
	str[len] = 0;
	return (str);
}
