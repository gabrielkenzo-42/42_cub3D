/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:56:34 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/28 15:35:47 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in(int c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_in(s1[i], set))
		i++;
	while (is_in(s1[j], set) && j > 0)
		j--;
	if (j < i)
	{
		str = malloc(1);
		*str = 0;
		return (str);
	}
	str = malloc(j - i + 2);
	if (!str)
		return (0);
	s1 += i;
	ft_strlcpy(str, s1, j - i + 2);
	return (str);
}
