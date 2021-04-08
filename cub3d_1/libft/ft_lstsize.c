/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:38:59 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/06 14:05:24 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cont;

	cont = 1;
	if (lst == 0)
		return (--cont);
	while (lst->next != 0)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}
