/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:44:05 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/02/07 20:02:37 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pot(int n, int p)
{
	int nbr;

	if (p < 0)
		return (0);
	nbr = 1;
	while (p-- > 0)
	{
		nbr *= n;
	}
	return (nbr);
}

static int	number_of_digits(int n)
{
	int ndigit;

	ndigit = 0;
	while (n != 0)
	{
		n /= 10;
		ndigit++;
	}
	return (ndigit);
}

static int	modulo(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*ptr;
	int		digit;

	digit = number_of_digits(n);
	str = malloc(digit + 2);
	if (!str)
		return (0);
	ptr = str;
	if (n < 0)
	{
		*ptr = '-';
		ptr++;
	}
	if (digit == 0)
		*ptr++ = 48;
	while (digit-- > 0)
	{
		*ptr++ = modulo(n / pot(10, digit)) + 48;
		n -= (n / pot(10, digit)) * pot(10, digit);
	}
	*ptr = 0;
	return (str);
}
