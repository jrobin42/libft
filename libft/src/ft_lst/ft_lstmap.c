/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 00:33:01 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 17:57:00 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lst_new;
	t_list		*begin;

	lst_new = NULL;
	if (lst && f)
	{
		if (!(begin = f(lst)))
			return (0);
		lst_new = begin;
		lst = lst->next;
		while (lst)
		{
			if (!(lst_new->next = f(lst)))
				return (NULL);
			lst_new = lst_new->next;
			lst = lst->next;
		}
		lst_new = NULL;
		return (begin);
	}
	return (0);
}
