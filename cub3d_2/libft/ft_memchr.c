/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:20:52 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/01/31 17:10:01 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void			*rets;
	unsigned char	newc;
	unsigned char	*news;

	rets = (void *)s;
	newc = c;
	news = (unsigned char *)s;
	while (n > 0)
	{
		if (*news == newc)
			return (rets);
		news++;
		rets++;
		n--;
	}
	return (NULL);
}
