/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 07:39:04 by gfloure           #+#    #+#             */
/*   Updated: 2017/01/14 18:06:55 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrwords(char const *str, char c)
{
	int		i;
	int		nbrwords;

	i = 0;
	nbrwords = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] != c && str[i])
				i++;
			nbrwords++;
		}
	}
	return (nbrwords);
}

static char	*ft_sncpy(char *dest, const char *str, int size)
{
	int		j;

	j = 0;
	while (j < size)
	{
		dest[j] = str[j];
		j++;
	}
	return (dest);
}

static void	ft_var(int *var, const char *str, char c)
{
	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	var[3] = 0;
	var[4] = ft_nbrwords(str, c);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		var[5];

	if (!s)
		return (NULL);
	ft_var(var, s, c);
	if ((tab = (char **)ft_memalloc(sizeof(char *) * (var[4] + 1))) == NULL)
		return (NULL);
	while (var[1] < var[4])
	{
		while (s[var[0]] != '\0' && s[var[0]] != c)
			var[0]++;
		var[2] = var[0] - var[3];
		if (var[2] != 0)
		{
			if (!(tab[var[1]] = (char *)malloc(sizeof(char) * (var[2] + 1))))
				return (NULL);
			ft_sncpy(tab[var[1]], (char const *)s + var[3], var[2]);
			tab[var[1]++][var[2]] = '\0';
		}
		var[0]++;
		var[3] = var[0];
	}
	tab[var[1]] = 0;
	return (tab);
}
