/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:30:31 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/17 13:34:28 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*newdest;
	unsigned char	*newsrc;

	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		newdest[i] = newsrc[i];
		if (newsrc[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
		n--;
	}
	return (0);
}
