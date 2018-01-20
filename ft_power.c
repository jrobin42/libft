/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 06:09:42 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/15 18:24:33 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_power(int nb, int power)
{
	int		save_nb;

	save_nb = nb;
	if (!power)
		return (1);
	while (power > 1)
	{
		nb = nb * save_nb;
		--power;
	}
	return (nb);
}
/*
int		main(void)
{
	printf("%d\n", ft_power(10, 0));
	return (0);
}*/
