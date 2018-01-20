/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:06:18 by jrobin            #+#    #+#             */
/*   Updated: 2017/12/06 19:11:51 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lst_insert_sort(t_list *insert, t_list **lst, int (*f)())
{
	//if (!f || !insert || !lst || !*lst)
	if (!f || !insert || !lst)
		return (1);
	while (*lst && (*lst)->content)
	{
		if (*lst && f(insert->content, (*lst)->content) <= 0)
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
