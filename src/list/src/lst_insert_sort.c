/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:06:18 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/25 21:25:12 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_list.h"

int		lst_insert_sort(t_list **lst, t_list *insert, int (*f)())
{
	if (!f || !insert || !lst)
		return (1);
	while (*lst && (*lst)->content)
	{
		if (insert->content && f(insert->content, (*lst)->content) <= 0)
		{
			insert->next = *lst;
			*lst = insert;
			return (0);
		}
		lst = &((*lst)->next);
	}
	*lst = insert;
	return (0);
}
