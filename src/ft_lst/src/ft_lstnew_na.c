/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 06:54:26 by jrobin            #+#    #+#             */
/*   Updated: 2018/04/29 00:01:46 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include "libft_mem.h"
#include <stdlib.h>

/*
**	lst new no allocated
*/

t_list	*ft_lstnew_na(void *content, size_t content_size)
{
	t_list		*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		exit(-1);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		new->content_size = content_size;
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
