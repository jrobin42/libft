/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:07:10 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 14:24:38 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*tab;

	if (!(tab = (void *)malloc(size)))
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
