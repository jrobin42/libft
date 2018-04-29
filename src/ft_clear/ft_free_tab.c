/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 07:40:54 by jrobin            #+#    #+#             */
/*   Updated: 2018/04/26 17:38:43 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_clear.h"
#include "ft_printf.h"
#include <stdio.h>

void	ft_free_tab(void ***tab)
{
	int		i;

	if (*tab)
	{
		i = 0;
		while ((*tab)[i])
		{
			ft_memdel(&((*tab)[i]));
			i++;
		}
	}
	ft_memdel((void**)tab);
}
