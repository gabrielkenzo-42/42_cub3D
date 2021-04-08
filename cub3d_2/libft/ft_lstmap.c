/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:27:33 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/06 14:12:07 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *copy;

	new = 0;
	while (lst)
	{
		if (!(copy = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, copy);
		lst = lst->next;
	}
	return (new);
}
