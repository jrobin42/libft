/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:28:01 by jrobin            #+#    #+#             */
/*   Updated: 2018/04/26 18:45:36 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nav1;
	t_list	*nav2;

	if (alst && *alst)
	{
		nav1 = *alst;
		while (nav1)
		{
			nav2 = nav1->next;
			ft_lstdelone(&nav1, del);
			if (nav2)
			{
				nav1 = nav2->next;
				ft_lstdelone(&nav2, del);
			}
		}
		*alst = NULL;
	}
}
