/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:55:12 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/19 11:12:49 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*newdest;
	const unsigned char	*newsrc;

	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (newdest == 0 && newsrc == 0)
		return (dest);
	while (n > 0)
	{
		*newdest = *newsrc;
		newdest++;
		newsrc++;
		n--;
	}
	return (dest);
}
