/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:01:54 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/06 14:07:40 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	copy = *lst;
	if (!copy)
		*lst = new;
	else
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}
