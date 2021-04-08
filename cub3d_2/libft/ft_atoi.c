/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:50:30 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/02 14:54:00 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sinal;
	int number;

	sinal = 1;
	i = 0;
	number = 0;
	while
		((str[i] != '\0') && (str[i] == ' ' || str[i] == '\f' ||
		str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sinal *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - 48);
	number = number * sinal;
	return (number);
}
