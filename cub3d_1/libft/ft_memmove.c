/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:46:09 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/19 13:29:05 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int					i;
	int					leng;
	unsigned char		*newdest;
	const unsigned char	*newsrc;

	leng = (int)len;
	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (newdest == 0 && newsrc == 0)
		return (dest);
	i = 0;
	if (newsrc < newdest)
		while (++i <= leng)
			newdest[leng - i] = newsrc[leng - i];
	else
		while (i < leng)
		{
			newdest[i] = newsrc[i];
			i++;
		}
	return (dest);
}
