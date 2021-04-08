/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maximum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:33:16 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/01/25 19:33:18 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	maximum(int arg_size, ...)
{
	int		max;
	int		current;
	va_list	numbers;

	va_start(numbers, arg_size);
	max = va_arg(numbers, int);
	while (--arg_size > 0)
	{
		current = va_arg(numbers, int);
		if (current > max)
			max = current;
	}
	va_end(numbers);
	return (max);
}
