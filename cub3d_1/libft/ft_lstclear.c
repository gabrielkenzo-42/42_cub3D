/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:56:00 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/06 14:15:08 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *prev;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		prev = *lst;
		*lst = prev->next;
		free(prev);
	}
	*lst = NULL;
}
