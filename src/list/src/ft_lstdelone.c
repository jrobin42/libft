/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:10:02 by jrobin            #+#    #+#             */
/*   Updated: 2018/04/26 18:40:00 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_list.h"
#include "f_memory.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
}
