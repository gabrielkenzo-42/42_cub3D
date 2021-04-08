/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:54:30 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/21 13:24:33 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	char		*ptrd1;
	char		*ptrd2;
	const char	*ptrs;

	if (!dest)
		return (0);
	ptrd1 = dest;
	ptrd2 = dest + destsize;
	ptrs = src;
	while (*ptrs && ptrd1 < ptrd2)
		*ptrd1++ = *ptrs++;
	if (ptrd1 < ptrd2)
		*ptrd1 = 0;
	else if (destsize > 0)
		ptrd1[-1] = 0;
	return (ft_strlen(src));
}
