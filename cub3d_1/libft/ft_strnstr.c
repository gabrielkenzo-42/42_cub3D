/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:59:46 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/05 16:55:54 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	char	*ptrb;
	int		i;

	ptrb = (char *)big;
	if (ft_strlen(small) == 0)
		return (ptrb);
	while (len > 0 && *big)
	{
		i = 0;
		while (*big++ == small[i])
		{
			if (i++ == (int)ft_strlen(small) - 1)
				return (ptrb);
			if (--len <= 0)
				return (NULL);
		}
		len -= 1;
		if (i > 0)
		{
			len += i;
			big--;
		}
		ptrb = (char *)big;
	}
	return (NULL);
}
