/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:48:08 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/11 20:27:15 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)str;
	i = ft_strlen(str);
	if (i == 0 && c == 0)
		return (ptr);
	if (i == 0 && c != 0)
		return (0);
	ptr += i;
	while (i >= 0)
	{
		if (str[i] == c)
			return (ptr);
		ptr--;
		i--;
	}
	return (0);
}
