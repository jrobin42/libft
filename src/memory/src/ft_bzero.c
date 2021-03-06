/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:05:38 by jrobin            #+#    #+#             */
/*   Updated: 2017/05/25 19:18:58 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"

void	ft_bzero(void *s, unsigned long n)
{
	ft_memset(s, 0, n);
}
