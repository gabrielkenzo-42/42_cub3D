/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:47:02 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/02 14:47:20 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ptr = str;
	while (*s)
		*ptr++ = *s++;
	*ptr = 0;
	return (str);
}
