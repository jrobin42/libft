/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:06:18 by jrobin            #+#    #+#             */
/*   Updated: 2017/12/06 11:37:48 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstinsert(t_list *insert, t_list **lst)
{
	t_list *tmp;
	if (insert && lst && *lst)
	{
		if (ft_strlen((*lst)->content) == 0)
			*lst = insert;
		else
		{
			insert->next = (*lst)->next;
			(*lst)->next = insert;
		}
		tmp = *lst;
		return (0);
	}
	return (1);
}
