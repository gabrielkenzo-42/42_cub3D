/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:11:32 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/01/25 20:11:33 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}
