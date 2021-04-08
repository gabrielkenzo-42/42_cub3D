/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:07:36 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/09 13:27:10 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (!s)
		return (0);
	str = malloc(len + 1);
	if (!str || (int)len == -1)
		return (0);
	ptr = str;
	while (len-- > 0 && start < ft_strlen(s))
		*ptr++ = s[start++];
	*ptr = 0;
	return (str);
}
