/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfloure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 05:44:36 by gfloure           #+#    #+#             */
/*   Updated: 2016/11/24 07:00:40 by gfloure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[j] != '\0')
	{
		i = 0;
		while (str[j + i] == to_find[i])
		{
			i++;
			if (to_find[i] == '\0')
				return (str + j);
		}
		j++;
	}
	return (0);
}
