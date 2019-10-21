/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:06:18 by jrobin            #+#    #+#             */
/*   Updated: 2018/04/19 18:23:48 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_list.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (alst && new)
	{
		if (*alst)
			begin = *alst;
		while (*alst)
		{
			if ((*alst)->next == NULL)
			{
				(*alst)->next = new;
				*alst = begin;
				return ;
			}
			*alst = (*alst)->next;
		}
		*alst = new;
	}
}
